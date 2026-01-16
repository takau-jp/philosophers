/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:41:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/16 17:07:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_ctx(t_ctx *ctx)
{
	int	i;

	free(ctx->philos);
	free(ctx->pthread_retvals);
	if (ctx->forks != NULL)
	{
		i = 0;
		while (i < ctx->n_philos)
		{
			pthread_mutex_destroy(&(ctx->forks[i]));
			i++;
		}
		free(ctx->forks);
	}
	pthread_mutex_destroy(&(ctx->monitor_mutex));
	pthread_mutex_destroy(&(ctx->print_mutex));
}
