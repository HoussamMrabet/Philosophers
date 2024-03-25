/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:05:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 16:19:14 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>
# include "error_msgs_bonus.h"

# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define FAILED 1

typedef struct s_table	t_table;
typedef int				t_bool;

typedef struct s_philo
{
	int			id;
	long		last_time_eat;
	long		rounds;
	t_bool		finish;
	t_bool		is_dead;
	sem_t		*philo_access;
	t_table		*table;
}	t_philo;

struct s_table
{
	int			nbrs_philo;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_to_die;
	long		init_time;
	pthread_t	monitor;
	sem_t		*forks_access;
	sem_t		*write_access;
	sem_t		*checker;
	t_philo		philo;
};

//custom functions
void	*ft_malloc(size_t s);
void	ft_pthread(pthread_t *thread, void *(*fn) (void *), void *arg, int i);
void	ft_semaphores(void *arg, int i);
void	ft_usleep(long usec);
void	ft_print(int status, t_table *table);

//utils
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
long	ft_atol(char *str);
char	*ft_strchr(const char *s, int c);
long	get_time(void);
void	ft_putstr_fd(char *msg, int fd);
void	ft_error(char *err);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);

//booleans
t_bool	is_finished(t_table *table);
t_bool	death_checker(void);
t_bool	is_died(t_table *table);

//philo
void	parser(int ac, char **av);
void	init_data(int ac, char **av, t_table *data);
void	dinning(t_table *table);
void	eating(t_table *table);
void	*monitoring(void *arg);

#endif