/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions_0_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:08:07 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/20 15:55:32 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_malloc(size_t s, t_philo *philo)
{
	void	*res;

	res = malloc(s);
	if (!res)
	{
		free(philo);
		exit(FAILED);
	}
	return (res);
}

static void	ft_pthread_err(int status, int i)
{
	if (status == EINVAL)
		ft_putstr_fd(EINVAL_ERR, 2);
	else if (i == 1)
	{
		if (status == EAGAIN)
			ft_putstr_fd(EAGAIN_ERR1 EAGAIN_ERR2 EAGAIN_ERR3 EAGAIN_ERR4, 2);
		else if (status == EPERM)
			ft_putstr_fd(EPERM_T_ERR1 EPERM_T_ERR2 EPERM_T_ERR3, 2);
	}
	else if (i == 2)
	{
		if (status == ESRCH)
			ft_putstr_fd(ESRCH_ERR1 ESRCH_ERR2, 2);
		else if (status == EDEADLK)
			ft_putstr_fd(EDEADLK_T_ERR1 EDEADLK_T_ERR2, 2);
	}
	else if (i == 3)
	{
		if (status == ESRCH)
			ft_putstr_fd(ESRCH_ERR1 ESRCH_ERR2, 2);
	}
}

void	ft_pthread(pthread_t *thread, void *(*fn) (void *), void *arg, int i)
{
	if (i == 1)
		ft_pthread_err(pthread_create(thread, NULL, fn, arg), i);
	else if (i == 2)
		ft_pthread_err(pthread_join(*thread, NULL), i);
	else if (i == 3)
		ft_pthread_err(pthread_detach(*thread), i);
}

static void	ft_semaphores_err(int status)
{
	if (status == EINVAL)
		ft_putstr_fd(EINVAL_S_ERR, 2);
	else if (status == EACCES)
		ft_putstr_fd(EACCESS_ERR1 EACCESS_ERR2 EACCESS_ERR3 EACCESS_ERR4, 2);
	else if (status == EINTR)
		ft_putstr_fd(EINTR_ERR, 2);
	else if (status == EMFILE)
		ft_putstr_fd(EMFILE_ERR1 EMFILE_ERR2, 2);
	else if (status == ENAMETOOLONG)
		ft_putstr_fd(ENAMETOOLONG_ERR, 2);
	else if (status == ENFILE)
		ft_putstr_fd(ENFILE_ERR, 2);
	else if (status == ENOENT)
		ft_putstr_fd(ENOENT_ERR, 2);
	else if (status == ENOSPC)
		ft_putstr_fd(ENOSPC_ERR1 ENOSPC_ERR2, 2);
	else if (status == EAGAIN)
		ft_putstr_fd(EAGAIN_ERR, 2);
	else if (status == EDEADLK)
		ft_putstr_fd(EDEADLK_ERR, 2);
}

void	ft_semaphores(void *arg, int i)
{
	if (i == 1)
		ft_semaphores_err(sem_post((sem_t *)arg));
	else if (i == 2)
		ft_semaphores_err(sem_wait((sem_t *)arg));
	else if (i == 3)
		ft_semaphores_err(sem_unlink((char *)arg));
	else if (i == 4)
		ft_semaphores_err(sem_close((sem_t *)arg));
}
