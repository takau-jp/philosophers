/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:37:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 20:37:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define DEF_COLOR "\033[0m"

# define ERROR_MSG_INVALID_ARGUMENTS "Invalid Argument\n\
\033[0;92m[Usage]: \033[0m\
\033[0;94mAll arguments must be positive integers (1 to INT_MAX)\033[0m\n\
Arguments: \n\
arg[1]: \033[0;93mnumber_of_philosophers\033[0m\n\
arg[2]: \033[0;93mtime_to_die\033[0m\n\
arg[3]: \033[0;93mtime_to_eat\033[0m\n\
arg[4]: \033[0;93mtime_to_sleep\033[0m\n\
arg[5]: \033[0;93mnumber_of_times_each_philosopher_must_eat\033[0m (optional)"

# define ERROR_MSG_MALLOC "Failed to allocate memory"
# define ERROR_MSG_INIT_MUTEX "Failed to initialize mutex object"
# define ERROR_MSG_CREATE_PTHREAD "Failed to create pthread"
# define ERROR_MSG_PRINT_STDOUT "Failed to print on stdout"

void	print_error_log(char *error);

#endif