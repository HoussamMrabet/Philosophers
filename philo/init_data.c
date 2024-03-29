/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 06:29:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/27 15:16:38 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbrs_philo)
	{
		ft_mutex(&table->forks[i].mtx, 1);
		(1) && (table->forks[i].id = i, i++);
	}
}

static void	init_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->nbrs_philo)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->is_dead = FALSE;
		philo->last_time_eat = get_time();
		philo->table = table;
		philo->rounds = table->rounds;
		philo->actif = TRUE;
		ft_mutex(&philo->philo_access, 1);
		philo->right_fork = &table->forks[i];
		philo->left_fork = &table->forks[(i + 1) % philo->table->nbrs_philo];
		i++;
	}
	philo = table->philos + i;
	philo = NULL;
}

void	init_data(int ac, char **av, t_table *table)
{
	table->nbrs_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->rounds = -1;
	table->ready = FALSE;
	table->finish = FALSE;
	table->philos_left = 0;
	ft_mutex(&table->write_access, 1);
	ft_mutex(&table->table_access, 1);
	table->philos = ft_malloc(sizeof(t_philo) * table->nbrs_philo, NULL);
	table->forks = ft_malloc(sizeof(t_fork) * table->nbrs_philo, table->philos);
	table->init_time = get_time();
	(ac == 6) && (table->rounds = ft_atol(av[5]));
	init_forks(table);
	init_philos(table);
}
