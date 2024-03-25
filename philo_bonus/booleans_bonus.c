/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booleans-0_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:49:21 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 12:50:31 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	is_finished(t_table *table)
{
	t_bool	value;

	ft_semaphores(table->philo.philo_access, 2);
	value = table->philo.finish || (table->philo.rounds == 0);
	ft_semaphores(table->philo.philo_access, 1);
	return (value);
}

t_bool	death_checker(void)
{
	sem_t	*sem;

	sem = sem_open("/death", AT_EACCESS, 0);
	if (sem == SEM_FAILED)
		return (FALSE);
	ft_semaphores(sem, 4);
	return (TRUE);
}

t_bool	is_died(t_table *table)
{
	t_bool	value;

	ft_semaphores(table->philo.philo_access, 2);
	value = get_time() - table->philo.last_time_eat > table->time_to_die;
	ft_semaphores(table->philo.philo_access, 1);
	return (value);
}
