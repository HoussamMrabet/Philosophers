/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:37:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/10 17:47:06 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine(t_philo *philo)
{
	ft_mutex(&philo->left_fork->mtx, 2);
	ft_print(1, philo->table->init_time, philo->id);
	ft_mutex(&philo->right_fork->mtx, 2);
	ft_print(1, philo->table->init_time, philo->id);
	ft_print(2, philo->table->init_time, philo->id);
	philo->last_time_eat = get_time();
	ft_usleep(philo->table->time_to_eat);
	ft_mutex(&philo->right_fork->mtx, 3);
	ft_mutex(&philo->left_fork->mtx, 3);
	ft_print(3, philo->table->init_time, philo->id);
	ft_usleep(philo->table->time_to_sleep);
	ft_print(4, philo->table->init_time, philo->id);
}

static void	*simulation(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!philo->table->ready)
		;
	if (philo->id % 2)
		ft_usleep(10);
	while (!philo->table->finish && philo->rounds)
	{
		if (philo->is_dead)
		{
			philo->table->finish = TRUE;
			return (NULL);
		}
		routine(philo);
		if (philo->rounds != -1)
			philo->rounds--;
	}
	philo->table->philos_left++;
	philo->actif = FALSE;
	return (NULL);
}

static void	*checker(void *param)
{
	t_table	*table;
	t_philo	*philo;
	int		i;

	table = param;
	philo = table->philos;
	i = 0;
	while (!table->finish && table->philos_left < table->nbrs_philo)
	{
		if (philo->actif
			&& (get_time() - philo->last_time_eat > table->time_to_die))
		{
			ft_print(5, philo->table->init_time, philo->id);
			philo->is_dead = TRUE;
			return (NULL);
		}
		philo++;
		i++;
		if (i == table->nbrs_philo)
		{
			philo = table->philos;
			i = 0;
		}
	}
	return (NULL);
}

void	dinning(t_table *table)
{
	t_philo		*philo;
	pthread_t	monitor;
	int			i;

	i = 0;
	philo = table->philos;
	if (!table->nbrs_philo)
		exit(SUCCESS);
	if (table->nbrs_philo == 1)
	{
		ft_print(1, table->init_time, 1);
		ft_usleep(table->time_to_die);
		ft_print(5, table->init_time, 1);
		ft_exit(table);
	}
	while (i < table->nbrs_philo)
	{
		ft_pthread(&philo->thread_id, simulation, philo, 1);
		ft_pthread(&philo->thread_id, NULL, NULL, 3);
		philo++;
		i++;
	}
	table->ready = TRUE;
	ft_pthread(&monitor, checker, table, 1);
	ft_pthread(&monitor, NULL, NULL, 2);
}
