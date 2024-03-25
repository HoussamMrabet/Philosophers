/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:51 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 12:48:40 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	clean_exit(sem_t *forks, sem_t *write)
{
	if (write)
		ft_semaphores(write, 4);
	if (forks)
		ft_semaphores(forks, 4);
	ft_putstr_fd("SEM FAILED\n", 2);
	exit(FAILED);
}

static void	unlinks(void)
{
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/checker");
}

static void	init_semaphores(t_table *table)
{
	unlinks();
	table->forks_access = sem_open("/forks", O_CREAT, 0777, table->nbrs_philo);
	table->write_access = sem_open("/write", O_CREAT, 0777, 1);
	table->checker = sem_open("/checker", O_CREAT, 0777, 1);
	if (table->forks_access == SEM_FAILED)
		clean_exit(NULL, NULL);
	if (table->write_access == SEM_FAILED)
		clean_exit(table->forks_access, NULL);
	if (table->checker == SEM_FAILED)
		clean_exit(table->forks_access, table->write_access);
	unlinks();
}

static void	init_philo(t_table *table, t_philo *philo)
{
	philo->is_dead = FALSE;
	philo->finish = FALSE;
	philo->last_time_eat = get_time();
	philo->table = table;
}

void	init_data(int ac, char **av, t_table *table)
{
	table->nbrs_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->init_time = get_time();
	table->philo.rounds = -1;
	(ac == 6) && (table->philo.rounds = ft_atol(av[5]));
	init_semaphores(table);
	init_philo(table, &table->philo);
}
