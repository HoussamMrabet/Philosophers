/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:42 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 07:14:29 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	die_alone(t_table *table)
{
	long	timestamp;

	timestamp = get_time() - table->init_time;
	printf("%-6ld 1 has taken a fork\n", timestamp);
	ft_usleep(table->time_to_die);
	timestamp = get_time() - table->init_time;
	printf("%-6ld 1 died\n", timestamp);
}

void	routine(void)
{
	exit(0);
}

void dinning(t_table *table)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (!table->nbrs_philo)
		exit(SUCCESS);
	if (table->nbrs_philo == 1)
		die_alone(table);
	else
	{
		while (i < table->nbrs_philo)
		{
			pid = fork();
			if (pid == 0)
				routine();
			else if (pid == -1)
			{
				free(table->philos);
				// close sema
				ft_putstr_fd("Fork error\n", 2);
				exit(FAILED);
			}
		}
		pid = waitpid(0, NULL, 0);
		while (pid != -1)
			pid = waitpid(0, NULL, 0);
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	parser(ac, av);
	init_data(ac, av, &table);
	dinning(&table);
	return (0);
}
