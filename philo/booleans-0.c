/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booleans-0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:57:56 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/12 01:00:56 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_died(t_philo *philo)
{
	t_bool	value;

	ft_mutex(&philo->philo_access, 2);
	value = get_time() - philo->last_time_eat > philo->table->time_to_die;
	ft_mutex(&philo->philo_access, 3);
	return (value);
}

t_bool	is_actif(t_philo *philo)
{
	t_bool	value;

	ft_mutex(&philo->philo_access, 2);
	value = philo->actif;
	ft_mutex(&philo->philo_access, 3);
	return (value);
}

t_bool	is_finished(t_table *table)
{
	t_bool	value;

	ft_mutex(&table->table_access, 2);
	value = table->finish;
	ft_mutex(&table->table_access, 3);
	return (value);
}

t_bool	is_full(t_table *table)
{
	t_bool	value;

	ft_mutex(&table->table_access, 2);
	value = table->philos_left < table->nbrs_philo;
	ft_mutex(&table->table_access, 3);
	return (value);
}
