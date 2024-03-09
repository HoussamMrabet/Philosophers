/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:05:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/02/24 07:32:44 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include "error_msgs_bonus.h"

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

void	parser(int ac, char **av);

// UTILS
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
long	ft_atol(char *str);
void	ft_putstr_fd(char *msg, int fd);
void	ft_error(char *err);

#endif