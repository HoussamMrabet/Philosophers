/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions_1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:26:52 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 16:19:46 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(long usec)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < usec)
		usleep(500);
}

void	ft_print(int status, t_table *table)
{
	long	timestamp;

	timestamp = get_time() - table->init_time;
	ft_semaphores(table->write_access, 2);
	if (status == 1 && !death_checker())
		printf("%-6ld %-3d has taken a fork\n", timestamp, table->philo.id);
	if (status == 2 && !death_checker())
		printf("%-6ld %-3d is eating\n", timestamp, table->philo.id);
	if (status == 3 && !death_checker())
		printf("%-6ld %-3d is sleeping\n", timestamp, table->philo.id);
	if (status == 4 && !death_checker())
		printf("%-6ld %-3d is thinking\n", timestamp, table->philo.id);
	if (status == 5 && !death_checker())
		printf("%-6ld %-3d died\n", timestamp, table->philo.id);
	ft_semaphores(table->write_access, 1);
}
