/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning-0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:37:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/12 01:06:51 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine(t_philo *philo)
{
	ft_mutex(&philo->left_fork->mtx, 2);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(1, philo, philo->table->finish);
	ft_mutex(&philo->table->table_access, 3);
	ft_mutex(&philo->right_fork->mtx, 2);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(1, philo, philo->table->finish);
	ft_mutex(&philo->table->table_access, 3);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(2, philo, philo->table->finish);
	ft_mutex(&philo->table->table_access, 3);
	eating(philo);
	ft_mutex(&philo->right_fork->mtx, 3);
	ft_mutex(&philo->left_fork->mtx, 3);
	sleeping(philo);
}

static void	*simulation(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!is_ready(philo))
		;
	if (philo->id % 2)
		ft_usleep(10);
	while (!is_finished(philo->table) && philo->rounds)
	{
		routine(philo);
		if (philo->rounds != -1)
			philo->rounds--;
	}
	ft_mutex(&philo->table->table_access, 2);
	philo->table->philos_left++;
	ft_mutex(&philo->table->table_access, 3);
	ft_mutex(&philo->philo_access, 2);
	philo->actif = FALSE;
	ft_mutex(&philo->philo_access, 3);
	return (NULL);
}

static void	*checker(void *param)
{
	t_table	*table;
	t_philo	*philo;
	int		i;

	(1) && (table = param, philo = table->philos, i = 0);
	while (!is_finished(table) && is_full(table))
	{
		if (is_actif(philo) && is_died(philo))
		{
			ft_print(5, philo, FALSE);
			ft_mutex(&table->table_access, 2);
			table->finish = TRUE;
			ft_mutex(&table->table_access, 3);
			break ;
		}
		(1) && (philo++, i++);
		if (i == table->nbrs_philo)
			(1) && (philo = table->philos, i = 0);
	}
	while (is_empty(table))
		;
	return (NULL);
}

static void	die_alone(t_table *table)
{
	long	timestamp;

	timestamp = get_time() - table->init_time;
	printf("%-6ld 1 has taken a fork\n", timestamp);
	ft_usleep(table->time_to_die);
	timestamp = get_time() - table->init_time;
	printf("%-6ld 1 died\n", timestamp);
	ft_exit(table);
}

void	dinning(t_table *table)
{
	t_philo		*philo;
	pthread_t	monitor;
	int			i;

	(1) && (i = -1, philo = table->philos);
	if (!table->nbrs_philo)
		exit(SUCCESS);
	if (table->nbrs_philo == 1)
		die_alone(table);
	while (++i < table->nbrs_philo)
	{
		ft_pthread(&philo->thread_id, simulation, philo, 1);
		philo++;
	}
	ft_mutex(&table->table_access, 2);
	table->ready = TRUE;
	ft_mutex(&table->table_access, 3);
	ft_pthread(&monitor, checker, table, 1);
	ft_pthread(&monitor, NULL, NULL, 2);
	(1) && (i = -1, philo = table->philos);
	while (++i < table->nbrs_philo)
	{
		ft_pthread(&philo->thread_id, NULL, NULL, 2);
		philo++;
	}
}
