/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:41:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/18 22:23:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_ctx(t_ctx *ctx, int n_philos)
{
	int	i;

	if (ctx->philos != NULL)
	{
		i = 0;
		while (i < n_philos)
		{
			pthread_mutex_destroy(&(ctx->philos[i].philo_mutex));
			i++;
		}
		free(ctx->philos);
	}
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
