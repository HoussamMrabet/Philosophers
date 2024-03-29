/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:05:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/12 01:08:44 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <errno.h>
# include <sys/time.h>
# include "error_msgs.h"

# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define FAILED 1

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mtx;
typedef int				t_bool;

typedef struct s_fork
{
	int		id;
	t_mtx	mtx;
}	t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	thread_id;
	long		last_time_eat;
	t_bool		is_dead;
	long		rounds;
	t_bool		actif;
	t_mtx		philo_access;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_table		*table;
}	t_philo;

struct s_table
{
	int		nbrs_philo;
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_die;
	long	rounds;
	long	init_time;
	long	philos_left;
	t_bool	finish;
	t_bool	ready;
	t_mtx	table_access;
	t_mtx	write_access;
	t_philo	*philos;
	t_fork	*forks;
};

//custom functions
void	*ft_malloc(size_t s, t_philo *philos);
void	ft_mutex(t_mtx *mtx, int i);
void	ft_pthread(pthread_t *thread, void *(*fn) (void *), void *arg, int i);
void	ft_usleep(long usec);
void	ft_print(int status, t_philo *philo, t_bool writer);

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
void	ft_exit(t_table *table);

//booleans
t_bool	is_died(t_philo *philo);
t_bool	is_actif(t_philo *philo);
t_bool	is_finished(t_table *table);
t_bool	is_full(t_table *table);
t_bool	is_ready(t_philo *philo);
t_bool	is_empty(t_table *table);

//philo
void	parser(int ac, char **av);
void	init_data(int ac, char **av, t_table *data);
void	dinning(t_table *table);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

#endif