/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:37:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/20 23:46:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ARGUMENT_ERROR "[Usage]: \033[0;93m./philo\033[0m\n\
arg[1]: \033[0;93mnumber_of_philosophers\033[0m [0 < n <= INT_MAX]\n\
arg[2]: \033[0;93mtime_to_die\033[0m [0 < n <= INT_MAX]\n\
arg[3]: \033[0;93mtime_to_eat\033[0m [0 < n <= INT_MAX]\n\
arg[4]: \033[0;93mtime_to_sleep\033[0m [0 < n <= INT_MAX]\n\
arg[5]: \033[0;93mnumber_of_times_each_philosopher_must_eat\033[0m \
[0 < n <= INT_MAX] (option)"
# define ERROR_MSG_MALLOC "Failed to allocate memory"
# define ERROR_MSG_INIT_MUTEX "Failed to initialize mutex object"
# define ERROR_MSG_GET_TIMEOFDAY "Failed to get time of day"
# define ERROR_MSG_CREATE_PTHREAD "Failed to create pthread"

void	print_error_log(char *error);

#endif