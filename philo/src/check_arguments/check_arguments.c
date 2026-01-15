/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:51:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/15 15:44:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_arguments(int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (false);
	if (is_int(argv[1]) == false || ft_atoi(argv[1]) <= 0)
		return (false);
	if (is_int(argv[2]) == false || ft_atoi(argv[2]) <= 0)
		return (false);
	if (is_int(argv[3]) == false || ft_atoi(argv[3]) <= 0)
		return (false);
	if (is_int(argv[4]) == false || ft_atoi(argv[4]) <= 0)
		return (false);
	if (argc == 6 && (is_int(argv[5]) == false || ft_atoi(argv[5]) <= 0))
		return (false);
	return (true);
}
