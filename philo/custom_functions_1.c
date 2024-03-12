/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:26:52 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/11 14:34:46 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long usec)
{
	long	start_time;
	long	target_time;
	long	curr_time;
	long	rem_time;

	start_time = get_time();
	if (start_time == -1)
		return ;
	target_time = start_time + usec;
	curr_time = get_time();
	while (curr_time != -1 && curr_time < target_time)
	{
		rem_time = (target_time - curr_time) / 2;
		if (rem_time > 1)
			usleep(rem_time * 1000);
		curr_time = get_time();
	}
}

void	ft_print(int status, long start, int id, t_bool writer, t_mtx write_access)
{
	long	timestamp;

	timestamp = get_time() - start;
	ft_mutex(&write_access, 2);
	if (status == 1 && !writer)
		printf("%-6ld %-3d has taken a fork\n", timestamp, id);
	if (status == 2 && !writer)
		printf("%-6ld %-3d is eating\n", timestamp, id);
	if (status == 3 && !writer)
		printf("%-6ld %-3d is sleeping\n", timestamp, id);
	if (status == 4 && !writer)
		printf("%-6ld %-3d is thinking\n", timestamp, id);
	if (status == 5 && !writer)
		printf("%-6ld %-3d died\n", timestamp, id);
	ft_mutex(&write_access, 3);
}
