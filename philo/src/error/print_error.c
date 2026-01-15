/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:31:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/15 15:42:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *error)
{
	ft_putstr_fd("\033[0;91m", STDERR_FILENO);
	ft_putendl_fd("ERROR", STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
}
