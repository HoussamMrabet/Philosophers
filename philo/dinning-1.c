/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning-1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:01:21 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/12 01:08:02 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	ft_mutex(&philo->philo_access, 2);
	philo->last_time_eat = get_time();
	ft_mutex(&philo->philo_access, 3);
	ft_usleep(philo->table->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	ft_mutex(&philo->table->table_access, 2);
	ft_print(3, philo, philo->table->finish);
	ft_mutex(&philo->table->table_access, 3);
	ft_usleep(philo->table->time_to_sleep);
	ft_mutex(&philo->table->table_access, 2);
	ft_print(4, philo, philo->table->finish);
	ft_mutex(&philo->table->table_access, 3);
}
