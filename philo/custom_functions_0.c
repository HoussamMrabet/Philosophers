/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:08:07 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/08 12:26:10 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_malloc(size_t s)
{
	void	*res;

	res = malloc(s);
	if (!res)
		exit(FAILED);
	return (res);
}

static void	ft_mutex_err(int status, int i)
{
	if (status == EINVAL)
		ft_putstr_fd(EINVAL_ERR, 2);
	if (i == 1 && status == ENOMEM)
		ft_putstr_fd(ENOMEM_ERR1 ENOMEM_ERR2, 2);
	else if (i == 2 && status == EDEADLK)
		ft_putstr_fd(EDEADLK_M_ERR1 EDEADLK_M_ERR2, 2);
	else if (i == 3 && status == EPERM)
		ft_putstr_fd(EPERM_M_ERR, 2);
	else if (i == 4 && status == EBUSY)
		ft_putstr_fd(EBUSY_ERR, 2);
}

void	ft_mutex(t_mtx *mtx, int i)
{
	if (i == 1)
		ft_mutex_err(pthread_mutex_init(mtx, NULL), i);
	else if (i == 2)
		ft_mutex_err(pthread_mutex_lock(mtx), i);
	else if (i == 3)
		ft_mutex_err(pthread_mutex_unlock(mtx), i);
	else if (i == 4)
		ft_mutex_err(pthread_mutex_destroy(mtx), i);
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
