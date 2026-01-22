/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:51:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 14:31:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_arguments(int argc, char *argv[]);
void	assign_arguments(int argc, char *argv[], t_settings *settings);

bool	parse_arguments(int argc, char *argv[], t_settings *settings)
{
	if (check_arguments(argc, argv) == false)
	{
		print_error_log(ERROR_MSG_INVALID_ARGUMENTS);
		return (false);
	}
	assign_arguments(argc, argv, settings);
	return (true);
}

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
	if (argc == 6)
	{
		if (is_int(argv[5]) == false || ft_atoi(argv[5]) <= 0)
			return (false);
	}
	return (true);
}

void	assign_arguments(int argc, char *argv[], t_settings *settings)
{
	settings->n_philos = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		settings->must_eat_counts = ft_atoi(argv[5]);
	else
		settings->must_eat_counts = NO_EAT_LIMIT;
}
