/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions_1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:26:52 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 06:57:27 by hmrabet          ###   ########.fr       */
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

void	ft_print(int status, t_philo *philo, t_bool wr)
{
	long	timestamp;

	timestamp = get_time() - philo->table->init_time;
	if (status == 1 && !wr)
		printf("%-6ld %-3d has taken a fork\n", timestamp, philo->id);
	if (status == 2 && !wr)
		printf("%-6ld %-3d is eating\n", timestamp, philo->id);
	if (status == 3 && !wr)
		printf("%-6ld %-3d is sleeping\n", timestamp, philo->id);
	if (status == 4 && !wr)
		printf("%-6ld %-3d is thinking\n", timestamp, philo->id);
	if (status == 5 && !wr)
		printf("%-6ld %-3d died\n", timestamp, philo->id);
}
