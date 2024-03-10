/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:06:25 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/10 17:55:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (*(str + i) && (*(str + i) == ' '
			|| (*(str + i) >= 9 && *(str + i) <= 13)))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign = -sign;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	return (sign * res);
}

long	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (0);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_putstr_fd(char *msg, int fd)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(fd, &msg[i], 1);
		i++;
	}
}

void	ft_error(char *err)
{
	ft_putstr_fd(RED"Error :\n"RESET" -> ", 2);
	ft_putstr_fd(err, 2);
	exit(FAILED);
}

void	ft_exit(t_table *table)
{
	free(table->philos);
	free(table->forks);
	exit(SUCCESS);
}
