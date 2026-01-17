/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:27:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_forks(t_ctx *ctx, int n_philos)
{
	int	i;

	ctx->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_philos);
	if (ctx->forks == NULL)
	{
		print_error(ERROR_MSG_MALLOC);
		return (false);
	}
	i = 0;
	while (i < n_philos)
	{
		if (pthread_mutex_init(&(ctx->forks[i]), NULL) != 0)
		{
			print_error(ERROR_MSG_INIT_MUTEX);
			while (i-- > 0)
				pthread_mutex_destroy(&(ctx->forks[i]));
			free(ctx->forks);
			ctx->forks = NULL;
			return (false);
		}	
		i++;
	}
	return (true);
}
