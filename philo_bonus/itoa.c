/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:24:56 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/25 10:25:11 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static size_t	count_length(int n)
{
	size_t	len;
	long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static size_t	ft_tenpow(size_t n)
{
	size_t	ten;

	ten = 1;
	if (n == 0)
		return (ten);
	while (n > 0)
	{
		ten *= 10;
		n--;
	}
	return (ten);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	long	nb;
	char	*res;

	len = count_length(n);
	res = (char *)malloc(len + 1);
	nb = n;
	i = 0;
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		*res = '-';
		nb = -nb;
		i++;
		len--;
	}
	while (len-- > 0)
	{
		*(res + i++) = ((nb / ft_tenpow(len)) % 10) + 48;
	}
	*(res + i) = '\0';
	return (res);
}
