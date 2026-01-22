/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_log.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:46:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 14:20:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error_log(char *error)
{
	ft_putendl_fd(RED "ERROR" DEF_COLOR, STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
}
