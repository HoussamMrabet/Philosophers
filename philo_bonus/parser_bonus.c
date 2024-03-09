/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:25:10 by hmrabet           #+#    #+#             */
/*   Updated: 2024/02/24 07:25:32 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	strlen_nbr(char *nbr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (nbr[i] && (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13)))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		i++;
		len++;
	}
	while (nbr[i] && nbr[i] == '0')
		i++;
	while (nbr[i] && (nbr[i] >= '0' && nbr[i] <= '9'))
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_checkchars(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (i == 0)
		{
			if (!((tmp[i] >= '0' && tmp[i] <= '9')
					|| tmp[i] == '+' || tmp[i] == '-'))
				return (1);
		}
		else
		{
			if (!(tmp[i] >= '0' && tmp[i] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}

static void	check_arguments(char **av, char *tmp, long arg1)
{
	int		i;

	i = 1;
	while (av[++i])
	{
		tmp = ft_strtrim(av[i], " \n\t");
		if (ft_checkchars(tmp) || strlen_nbr(tmp) > 11
			|| ft_atol(tmp) > INT_MAX
			|| (i != 5 && ft_atol(tmp) < 60))
		{
			free(tmp);
			if (i == 5)
				ft_error(MEAL_ARG1 MEAL_ARG1);
			else
				ft_error(TIME_ARG1 TIME_ARG2);
		}
		free(tmp);
	}
}

void	parser(int ac, char **av)
{
	char	*tmp;
	long	arg1;

	if (ac > 6)
		ft_error("too many arguments!\n");
	if (ac < 5)
		ft_error("too few arguments!\n");
	tmp = ft_strtrim(av[1], " \n\t");
	arg1 = ft_atol(tmp);
	if (ft_checkchars(tmp) || strlen_nbr(tmp) > 11
		|| arg1 > INT_MAX || arg1 < 0)
	{
		free(tmp);
		ft_error("invalid number of philosophers\n");
	}
	free(tmp);
	check_arguments(av, tmp, arg1);
	if (!arg1)
		exit(SUCCESS);
}
