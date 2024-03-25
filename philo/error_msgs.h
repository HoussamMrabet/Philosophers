/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:59:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/12 15:47:06 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

// PARSING ERRORS
# define MEAL_ARG1 "the number of times each philosopher "
# define MEAL_ARG2 "must eat should be positive\n"
# define TIME_ARG1 "time values should be valid number and lower "
# define TIME_ARG2 "than 60 ms or upper than INT_MAX\n"

// MUTEX ERRORS
# define EINVAL_ERR "The value specified by attr is invalid.\n"
# define ENOMEM_ERR1 "The process cannot allocate enough "
# define ENOMEM_ERR2 "memory to create another mutex.\n"
# define EDEADLK_M_ERR1 "A deadlock would occur if the "
# define EDEADLK_M_ERR2 "thread blocked waiting for mutex.\n"
# define EPERM_M_ERR "The current thread does not hold a lock on mutex.\n"
# define EBUSY_ERR "Mutex is locked.\n"

// THREADS ERRORS
# define EAGAIN_ERR1 "The system lacked the necessary resources "
# define EAGAIN_ERR2 "to create another thread, or the system-imposed "
# define EAGAIN_ERR3 "limit on the total number of threads in a "
# define EAGAIN_ERR4 "process [PTHREAD_THREADS_MAX] would be exceeded.\n"
# define EPERM_T_ERR1 "The caller does not have appropriate permission to set"
# define EPERM_T_ERR2 " the required scheduling parameters "
# define EPERM_T_ERR3 "or scheduling policy.\n"
# define ESRCH_ERR1 "No thread could be found corresponding to that specified "
# define ESRCH_ERR2 "by the given thread ID, thread.\n"
# define EDEADLK_T_ERR1 "A deadlock was detected or the value of "
# define EDEADLK_T_ERR2 "thread specifies the calling thread.\n"

#endif