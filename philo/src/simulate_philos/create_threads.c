/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:16:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 23:05:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_threads(t_ctx *ctx, int n_philos, t_simulation *simulation)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < n_philos)
	{
		philo = &(ctx->philos[i]);
		if (pthread_create(&(philo->thread), NULL, philo_routine, philo) != 0)
		{
			simulation->state = STATE_ERROR;
			pthread_mutex_unlock(&(simulation->state_mutex));
			while (i-- > 0)
			{
				philo = &(ctx->philos[i]);
				pthread_join(philo->thread, NULL);
			}
			return (false);
		}
		i++;
	}
	return (true);
}
