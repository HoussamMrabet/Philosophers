/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning-1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:36 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 16:18:57 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int_fast16_t	end_simulation(t_table *table)
{
	if (is_died(table) && !death_checker())
	{
		ft_semaphores(table->philo.philo_access, 2);
		table->philo.is_dead = TRUE;
		table->philo.finish = TRUE;
		ft_print(5, table);
		ft_semaphores(table->philo.philo_access, 1);
		sem_open("/death", O_CREAT, 0777, 0);
		ft_semaphores(table->checker, 1);
		return (1);
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (!is_finished(table))
	{
		if (death_checker())
		{
			ft_semaphores(table->philo.philo_access, 2);
			table->philo.finish = TRUE;
			ft_semaphores(table->philo.philo_access, 1);
			return (NULL);
		}
		ft_semaphores(table->checker, 2);
		if (end_simulation(table))
			return (NULL);
		ft_semaphores(table->checker, 1);
		usleep(500);
	}
	return (NULL);
}

void	eating(t_table *table)
{
	ft_semaphores(table->forks_access, 2);
	ft_print(1, table);
	ft_semaphores(table->forks_access, 2);
	if (is_finished(table))
	{
		ft_semaphores(table->forks_access, 1);
		ft_semaphores(table->forks_access, 1);
		return ;
	}
	ft_print(1, table);
	ft_semaphores(table->philo.philo_access, 2);
	table->philo.last_time_eat = get_time();
	ft_semaphores(table->philo.philo_access, 1);
	ft_print(2, table);
	ft_usleep(table->time_to_eat);
	ft_semaphores(table->philo.philo_access, 2);
	table->philo.rounds--;
	ft_semaphores(table->philo.philo_access, 1);
	ft_semaphores(table->forks_access, 1);
	ft_semaphores(table->forks_access, 1);
}
