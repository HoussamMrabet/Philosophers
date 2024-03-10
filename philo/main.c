/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:42 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/09 20:29:05 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_print(int status, long start, int id)
{
	long	timestamp;

	timestamp = get_time() - start;
	if (status == 1)
		printf("%-6ld %-3d has taken a fork\n", timestamp, id);
	if (status == 2)
		printf("%-6ld %-3d is eating\n", timestamp, id);
	if (status == 3)
		printf("%-6ld %-3d is sleeping\n", timestamp, id);
	if (status == 4)
		printf("%-6ld %-3d is thinking\n", timestamp, id);
	if (status == 5)
		printf("%-6ld %-3d died\n", timestamp, id);
}

void	ft_exit(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbrs_philo)
	{
		free(table->philos + i);
		free(table->forks + i);
		i++;
	}
	exit(SUCCESS);
}

void	*simulation(void *param)
{
	t_philo *philo;

	philo = param;
	while (!philo->table->ready)
		;
	while (!philo->table->finish && philo->table->rounds)
	{
		ft_mutex(&philo->left_fork->mtx, 2);
		ft_mutex(&philo->right_fork->mtx, 2);
		ft_print(1, philo->table->init_time, philo->id);
		ft_print(1, philo->table->init_time, philo->id);
		ft_print(2, philo->table->init_time, philo->id);
		usleep(1000 * philo->table->time_to_eat);
		ft_print(3, philo->table->init_time, philo->id);
		ft_mutex(&philo->right_fork->mtx, 3);
		ft_mutex(&philo->left_fork->mtx, 3);
		usleep(1000 * philo->table->time_to_sleep);
		ft_print(4, philo->table->init_time, philo->id);
	}
	return (NULL);
}

void	*test1(void *param)
{
	t_table	*table;

	table = param;
	sleep(5);
	table->finish = TRUE;
	return (NULL);
}

void	*checker(void *param)
{
	t_table	*table;
	
	table = param;
	while (!table->finish)
		;
	return (NULL);
}

void	dinning(t_table *table)
{
	int			i;
	t_philo		*philo;
	pthread_t	monitor;
	pthread_t	test;

	i = 0;
	philo = table->philos;
	if (!table->nbrs_philo)
		exit(SUCCESS);
	if (table->nbrs_philo == 1)
	{
		ft_print(1, table->init_time, 1);
		usleep(table->time_to_die * 1000);
		ft_print(5, table->init_time, 1);
		ft_exit(table);
	}
	while (i < table->nbrs_philo)
	{
		ft_pthread(&philo->thread_id, simulation, philo, 1);
		philo++;
		i++;
	}
	table->ready = TRUE;
	ft_pthread(&monitor, checker, table, 1);
	ft_pthread(&test, test1, table, 1);
	ft_pthread(&monitor, NULL, NULL, 2);
	ft_pthread(&test, NULL, NULL, 2);
}

void leaks(){system("leaks philo");}

int	main(int ac, char **av)
{
	t_table	table;

	// atexit(leaks);
	parser(ac, av);
	init_data(ac, av, &table);
	dinning(&table);
}
