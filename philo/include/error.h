/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:37:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/15 15:45:35 by stanaka2         ###   ########.fr       */
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

void	print_error(char *error);

#endif