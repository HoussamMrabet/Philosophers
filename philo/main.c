/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:42 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/10 12:22:21 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_print(int status, long start, int id)
{
	long timestamp;

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

void ft_exit(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nbrs_philo)
	{
		free(table->philos + i);
		free(table->forks + i);
		i++;
	}
	exit(SUCCESS);
}

void *simulation(void *param)
{
	t_philo *philo;

	philo = param;
	while (!philo->table->ready)
		;
	if (philo->id % 2)
		ft_usleep(philo->table->time_to_die / 2);
	while (!philo->table->finish && philo->rounds)
	{
		if (philo->is_dead)
		{
			philo->table->finish = TRUE;
			return (NULL);
		}
		ft_mutex(&philo->left_fork->mtx, 2);
		ft_mutex(&philo->right_fork->mtx, 2);
		ft_mutex(&philo->table->printer, 2);
		ft_print(1, philo->table->init_time, philo->id);
		ft_mutex(&philo->table->printer, 3);
		ft_mutex(&philo->table->printer, 2);
		ft_print(1, philo->table->init_time, philo->id);
		ft_mutex(&philo->table->printer, 3);
		ft_mutex(&philo->table->printer, 2);
		ft_print(2, philo->table->init_time, philo->id);
		ft_mutex(&philo->table->printer, 3);
		ft_usleep(philo->table->time_to_eat);
		philo->last_time_eat = get_time();
		ft_mutex(&philo->table->printer, 2);
		ft_print(3, philo->table->init_time, philo->id);
		ft_mutex(&philo->table->printer, 3);
		ft_mutex(&philo->right_fork->mtx, 3);
		ft_mutex(&philo->left_fork->mtx, 3);
		ft_usleep(philo->table->time_to_sleep);
		ft_mutex(&philo->table->printer, 2);
		ft_print(4, philo->table->init_time, philo->id);
		ft_mutex(&philo->table->printer, 3);
		if (philo->rounds != -1)
			philo->rounds--;
	}
	philo->table->philos_left++;
	return (NULL);
}

void *checker(void *param)
{
	t_table *table;
	t_philo *philo;
	int i;

	table = param;
	philo = table->philos;
	i = 0;
	while (!table->finish && table->philos_left < table->nbrs_philo)
	{
		if (get_time() - philo->last_time_eat > table->time_to_die)
		{
			ft_mutex(&philo->table->printer, 2);
			ft_print(5, philo->table->init_time, philo->id);
			ft_mutex(&philo->table->printer, 3);
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

void dinning(t_table *table)
{
	int i;
	t_philo *philo;
	pthread_t monitor;

	i = 0;
	philo = table->philos;
	if (!table->nbrs_philo)
		exit(SUCCESS);
	if (table->nbrs_philo == 1)
	{
		ft_print(1, table->init_time, 1);
		ft_usleep(table->time_to_die * 1000);
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
	ft_pthread(&monitor, NULL, NULL, 2);
}

void leaks() { system("leaks philo"); }

int main(int ac, char **av)
{
	t_table table;

	// atexit(leaks);
	parser(ac, av);
	init_data(ac, av, &table);
	dinning(&table);
}
