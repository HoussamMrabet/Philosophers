/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:42 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/09 10:52:04 by hmrabet          ###   ########.fr       */
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

void dinning(t_table *table)
{
	int	i;

	i = 0;
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
		
		i++;
	}
}

void leaks(){system("leaks philo");}

int	main(int ac, char **av)
{
	t_table	table;

	atexit(leaks);
	parser(ac, av);
	init_data(ac, av, &table);
	dinning(&table);
}
