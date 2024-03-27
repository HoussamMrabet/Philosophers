/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning-0_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:52:05 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/27 15:45:56 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*get_sem_name(int id)
{
	char	*philo_id;
	char	*sem_name;

	philo_id = ft_itoa(id);
	sem_name = ft_strjoin("/philo_", philo_id);
	free(philo_id);
	return (sem_name);
}

static void	set_philo(t_table *table, int id)
{
	char	*sem_name;

	table->philo.id = id;
	sem_name = get_sem_name(id);
	if (sem_name == NULL)
		exit(FAILED);
	ft_semaphores(sem_name, 3);
	table->philo.philo_access = sem_open(sem_name, O_CREAT, 0777, 1);
	ft_semaphores(sem_name, 3);
	free(sem_name);
	ft_semaphores(table->philo.philo_access, 2);
	table->philo.last_time_eat = get_time();
	ft_semaphores(table->philo.philo_access, 1);
}

static void	die_alone(t_table *table)
{
	long	timestamp;

	timestamp = get_time() - table->init_time;
	printf("%-6ld 1 has taken a fork\n", timestamp);
	ft_usleep(table->time_to_die);
	timestamp = get_time() - table->init_time;
	printf("%-6ld 1 died\n", timestamp);
}

static void	routine(t_table *table, int id)
{
	set_philo(table, id);
	if (!(table->philo.id % 2))
		ft_usleep(10);
	ft_pthread(&table->monitor, monitoring, table, 1);
	while (!is_finished(table))
	{
		eating(table);
		ft_print(3, table);
		ft_usleep(table->time_to_sleep);
		ft_print(4, table);
	}
	ft_pthread(&table->monitor, NULL, NULL, 2);
	ft_semaphores(table->philo.philo_access, 4);
	exit(SUCCESS);
}

void	dinning(t_table *table)
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
		while (i++ < table->nbrs_philo)
		{
			pid = fork();
			if (pid == 0)
				routine(table, i);
			else if (pid == -1)
			{
				ft_putstr_fd("Fork error\n", 2);
				exit(FAILED);
			}
		}
		pid = waitpid(0, NULL, 0);
		while (pid != -1)
			pid = waitpid(0, NULL, 0);
	}
}
