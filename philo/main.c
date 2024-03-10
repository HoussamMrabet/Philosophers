/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:42 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/10 17:55:14 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleaning(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbrs_philo)
	{
		ft_mutex(&table->forks[i].mtx, 4);
		i++;
	}
	free(table->forks);
	free(table->philos);
}

int	main(int ac, char **av)
{
	t_table	table;

	parser(ac, av);
	init_data(ac, av, &table);
	dinning(&table);
	cleaning(&table);
}
