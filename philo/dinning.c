/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:37:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/11 14:49:12 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_died(t_philo *philo)
{
	t_bool	value;

	ft_mutex(&philo->philo_access, 2);
	value = get_time() - philo->last_time_eat > philo->table->time_to_die;
	ft_mutex(&philo->philo_access, 3);
	return (value);
}

static t_bool	is_actif(t_philo *philo)
{
	t_bool	value;

	ft_mutex(&philo->philo_access, 2);
	value = philo->actif;
	ft_mutex(&philo->philo_access, 3);
	return (value);
}

static t_bool	is_finished(t_table *table)
{
	t_bool	value;

	ft_mutex(&table->table_access, 2);
	value = table->finish;
	ft_mutex(&table->table_access, 3);
	return (value);
}

static t_bool	is_full(t_table *table)
{
	t_bool	value;

	ft_mutex(&table->table_access, 2);
	value = table->philos_left < table->nbrs_philo;
	ft_mutex(&table->table_access, 3);
	return (value);
}

static void	eating(t_philo *philo)
{
	ft_mutex(&philo->philo_access, 2);
	philo->last_time_eat = get_time();
	ft_mutex(&philo->philo_access, 3);
	ft_usleep(philo->table->time_to_eat);
}

static void	sleeping(t_philo *philo)
{
	ft_mutex(&philo->table->table_access, 2);
	ft_print(3, philo->table->init_time, philo->id, philo->table->finish, philo->table->write_access);
	ft_mutex(&philo->table->table_access, 3);
	ft_usleep(philo->table->time_to_sleep);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(4, philo->table->init_time, philo->id, philo->table->finish, philo->table->write_access);
	ft_mutex(&philo->table->table_access, 3);
}

static void	routine(t_philo *philo)
{
	ft_mutex(&philo->left_fork->mtx, 2);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(1, philo->table->init_time, philo->id, philo->table->finish, philo->table->write_access);
	ft_mutex(&philo->table->table_access, 3);
	ft_mutex(&philo->right_fork->mtx, 2);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(1, philo->table->init_time, philo->id, philo->table->finish, philo->table->write_access);
	ft_mutex(&philo->table->table_access, 3);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(2, philo->table->init_time, philo->id, philo->table->finish, philo->table->write_access);
	ft_mutex(&philo->table->table_access, 3);
	eating(philo);
	ft_mutex(&philo->right_fork->mtx, 3);
	ft_mutex(&philo->left_fork->mtx, 3);
	sleeping(philo);
}

static t_bool	is_ready(t_philo *philo)
{
	t_bool	value;

	ft_mutex(&philo->table->table_access, 2);
	value = philo->table->ready;
	ft_mutex(&philo->table->table_access, 3);
	return (value);
}

static t_bool	is_empty(t_table *table)
{
	t_bool	value;

	ft_mutex(&table->table_access, 2);
	value = (table->philos_left < table->nbrs_philo);
	ft_mutex(&table->table_access, 3);
	return (value);
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

	table = param;
	philo = table->philos;
	i = 0;
	while (!is_finished(table) && is_full(table))
	{
		if (is_actif(philo) && is_died(philo))
		{
			ft_print(5, philo->table->init_time, philo->id, FALSE, philo->table->write_access);
			ft_mutex(&table->table_access, 2);
			table->finish = TRUE;
			ft_mutex(&table->table_access, 3);
			break ;
		}
		philo++;
		i++;
		if (i == table->nbrs_philo)
		{
			philo = table->philos;
			i = 0;
		}
	}
	while (is_empty(table))
		;
	return (NULL);
}

static void	die_alone(t_table *table)
{
	ft_print(1, table->init_time, 1, FALSE, table->write_access);
	ft_usleep(table->time_to_die);
	ft_print(5, table->init_time, 1, FALSE, table->write_access);
	ft_exit(table);
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
		die_alone(table);
	while (i < table->nbrs_philo)
	{
		ft_pthread(&philo->thread_id, simulation, philo, 1);
		philo++;
		i++;
	}
	ft_mutex(&table->table_access, 2);
	table->ready = TRUE;
	ft_mutex(&table->table_access, 3);
	ft_pthread(&monitor, checker, table, 1);
	ft_pthread(&monitor, NULL, NULL, 2);
	i = 0;
	philo = table->philos;
	while (i < table->nbrs_philo)
	{
		ft_pthread(&philo->thread_id, NULL, NULL, 2);
		philo++;
		i++;
	}
}
