/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:42:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 23:22:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philos(t_ctx *ctx, t_settings *settings, t_simulation *simulation)
{
	int	i;

	ctx->philos = (t_philo *)malloc(sizeof(t_philo) * settings->n_philos);
	if (ctx->philos == NULL)
	{
		print_error(ERROR_MSG_MALLOC);
		return (false);
	}
	i = 0;
	while (i < settings->n_philos)
	{
		ctx->philos[i].index = i + 1;
		ctx->philos[i].right = &(ctx->forks[i]);
		if (i != settings->n_philos - 1)
			ctx->philos[i].left = &(ctx->forks[i + 1]);
		else
			ctx->philos[i].left = &(ctx->forks[0]);
		ctx->philos[i].eat_count = 0;
		ctx->philos[i].settings = settings;
		ctx->philos[i].simulation = simulation;
		i++;
	}
	return (true);
}
