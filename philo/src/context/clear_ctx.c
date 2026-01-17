/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:41:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 18:43:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_ctx(t_ctx *ctx, int n_philos)
{
	int	i;

	free(ctx->philos);
	free(ctx->pthread_retvals);
	if (ctx->forks != NULL)
	{
		i = 0;
		while (i < n_philos)
		{
			pthread_mutex_destroy(&(ctx->forks[i]));
			i++;
		}
		free(ctx->forks);
	}
}
