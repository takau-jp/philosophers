/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:51:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/16 17:01:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_arguments(int argc, char *argv[]);
void	assign_arguments(t_ctx *ctx, int argc, char *argv[]);

bool	parse_arguments(t_ctx *ctx, int argc, char *argv[])
{
	if (check_arguments(argc, argv) == false)
	{
		print_error(ARGUMENT_ERROR);
		return (false);
	}
	assign_arguments(ctx, argc, argv);
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

void	assign_arguments(t_ctx *ctx, int argc, char *argv[])
{
	ctx->n_philos = ft_atoi(argv[1]);
	ctx->time_to_die = ft_atoi(argv[2]);
	ctx->time_to_eat = ft_atoi(argv[3]);
	ctx->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ctx->must_eat_counts = ft_atoi(argv[5]);
	else
		ctx->must_eat_counts = NO_EAT_LIMIT;
}
