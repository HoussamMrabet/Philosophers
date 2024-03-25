/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:42 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 13:02:12 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	cleanup(t_table *table)
{
	ft_semaphores(table->forks_access, 4);
	ft_semaphores(table->write_access, 4);
	ft_semaphores(table->checker, 4);
}

int	main(int ac, char **av)
{
	t_table	table;

	parser(ac, av);
	init_data(ac, av, &table);
	dinning(&table);
	cleanup(&table);
	return (0);
}
