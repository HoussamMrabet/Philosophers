/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booleans-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:00:43 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/12 01:01:02 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_ready(t_philo *philo)
{
	t_bool	value;

	ft_mutex(&philo->table->table_access, 2);
	value = philo->table->ready;
	ft_mutex(&philo->table->table_access, 3);
	return (value);
}

t_bool	is_empty(t_table *table)
{
	t_bool	value;

	ft_mutex(&table->table_access, 2);
	value = (table->philos_left < table->nbrs_philo);
	ft_mutex(&table->table_access, 3);
	return (value);
}
