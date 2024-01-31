/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:42 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/31 11:14:19 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_error(char *err)
{
	printf(RED"Error :\n"RESET" -> %s", err);
	exit(FAILED);
}

void	parser(int ac, char **av)
{
	int	i;

	i = 2;
	if (ac > 6)
		ft_error("too many arguments!\n");
	if (ac < 5)
		ft_error("too few arguments!\n");
	while (i < 5)
	{
		if (ft_atol(av[i]) < 60)
			ft_error("time values shouldn't be lower than 60 ms\n");
		i++;
	}
	exit(SUCCESS);
}

int	main(int ac, char **av)
{
	parser(ac, av);
}
