/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 06:29:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/09 10:21:56 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void get_forks(t_philo *philo, t_fork *forks, int philo_id)
{
	if (!(philo->id % 2))
	{
		philo->left_fork = &forks[philo_id];
		philo->right_fork = &forks[(philo_id + 1) % philo->table->nbrs_philo];
	}
	else
	{
		philo->left_fork = &forks[(philo_id + 1) % philo->table->nbrs_philo];
		philo->right_fork = &forks[philo_id];
	}
}

static void init_forks(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nbrs_philo)
	{
		ft_mutex(&table->forks[i].mtx, 1);
		(1) && (table->forks[i].id = i, i++);
	}
}

static void init_philos(t_table *table)
{
	int i;
	t_philo *philo;

	i = 0;
	while (i < table->nbrs_philo)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->is_dead = FALSE;
		philo->last_time_eat = get_time();
		philo->table = table;
		get_forks(philo, table->forks, i);
		i++;
	}
}

void init_data(int ac, char **av, t_table *table)
{
	table->nbrs_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->rounds = -1;
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->philos = ft_malloc(sizeof(t_philo) * table->nbrs_philo);
	table->forks = ft_malloc(sizeof(t_fork) * table->nbrs_philo);
	table->init_time = get_time();
	(ac == 6) && (table->rounds = ft_atol(av[5]));
	init_forks(table);
	init_philos(table);
}
