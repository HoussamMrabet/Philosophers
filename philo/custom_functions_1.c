/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:26:52 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/10 12:17:57 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_usleep(long usec)
{
    long    start_time;
    long    target_time;
    long    curr_time;
    long    rem_time;

    start_time = get_time();
    if (start_time == -1)
        return ;
    target_time = start_time + usec;
    curr_time = get_time();
    while (curr_time != -1 && curr_time < target_time)
    {
        rem_time = (target_time - curr_time) / 2;
        if (rem_time > 1)
            usleep(rem_time * 1000);
        curr_time = get_time();
    }
}
