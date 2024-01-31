/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:05:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/31 11:14:42 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"
# define SUCCESS 0
# define FAILED 1

typedef struct s_fork
{
	int	id;
}	t_fork;

typedef struct s_philo
{
	int		id;
	int		alive;
	long	sleep;
	long	eat;
	long	life;
	t_fork	left;
	t_fork	right;
}	t_philo;

#endif