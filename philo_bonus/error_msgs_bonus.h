/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:59:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/03/20 15:41:42 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_BONUS_H
# define ERROR_MSGS_BONUS_H

// PARSING ERRORS
# define MEAL_ARG1 "the number of times each philosopher "
# define MEAL_ARG2 "must eat should be positive\n"
# define TIME_ARG1 "time values should be valid number and lower "
# define TIME_ARG2 "than 60 ms or upper than INT_MAX\n"

// THREADS ERRORS
# define EINVAL_ERR "The value specified by attr is invalid.\n"
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

// SEMAPHORES ERRORS
# define EINVAL_S_ERR "sem is not a valid semaphore descriptor.\n"
# define EACCESS_ERR1 "The required permissions (for reading and/or writing) are "
# define EACCESS_ERR2 "denied for the given flags; or O_CREAT is specified, "
# define EACCESS_ERR3 "the object does not exist, and permission to create "
# define EACCESS_ERR4 "the semaphore is denied.\n"
# define EEXIST_ERR "O_CREAT and O_EXCL were specified and the semaphore exists.\n"
# define EINTR_ERR "The call was interrupted by a signal.\n"
# define EMFILE_ERR1 "The process has already reached its limit for semaphores "
# define EMFILE_ERR2 "or file descriptors in use.\n"
# define ENAMETOOLONG_ERR "name exceeded PSEMNAMLEN characters.\n"
# define ENFILE_ERR "Too many semaphores or file descriptors are open on the system.\n"
# define ENOENT_ERR "O_CREAT is not set and the named semaphore does not exist.\n"
# define ENOSPC_ERR1 "O_CREAT is specified, the file does not exist, and there "
# define ENOSPC_ERR2 "is insufficient space available to create the semaphore.\n"
# define EAGAIN_ERR "The semaphore is already locked.\n"
# define EDEADLK_ERR "A deadlock was detected.\n"

#endif