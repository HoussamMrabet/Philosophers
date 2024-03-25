/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:51 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 06:58:01 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphores(t_table *table)
{
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/write");
	table->forks_access = sem_open("/forks", O_CREAT, 0644, table->nbrs_philo);
	table->write_access = sem_open("/write", O_CREAT, 0644, 1);
	if (table->forks_access == SEM_FAILED)
	{
		free(table->philos);
		ft_putstr_fd("SEM FAILED\n", 2);
		exit(FAILED);
	}
	if (table->forks_access == SEM_FAILED)
	{
		free(table->philos);
		ft_semaphores(table->forks_access, 4);
		ft_putstr_fd("SEM FAILED\n", 2);
		exit(FAILED);
	}	
	sem_unlink("/forks");
	sem_unlink("/write");
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
		i++;
	}
	philo = table->philos + i;
	philo = NULL;
}

void	init_data(int ac, char **av, t_table *table)
{
	table->nbrs_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->rounds = -1;
	table->ready = FALSE;
	table->finish = FALSE;
	table->philos_left = 0;
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->philos = ft_malloc(sizeof(t_philo) * table->nbrs_philo, NULL);
	table->init_time = get_time();
	(ac == 6) && (table->rounds = ft_atol(av[5]));
	init_semaphores(table);
	init_philos(table);
}
