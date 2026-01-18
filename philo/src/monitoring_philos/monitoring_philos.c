/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:51:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/18 21:48:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	monitoring_philos(t_ctx *ctx, t_settings settings, t_simulation *simulation)
{
	while (true)
	{
		pthread_mutex_lock(&(simulation->state_mutex));
		if (simulation->state == STATE_ERROR)
		{
			pthread_mutex_unlock(&(simulation->state_mutex));
			return (false);
		}
		if (simulation->state == STATE_DEAD)
		{
			pthread_mutex_unlock(&(simulation->state_mutex));
			return (true);
		}
		if (settings.must_eat_counts > 0)
		{
			if (simulation->finished_philos_count == settings.n_philos)
			{
				simulation->state = STATE_END;
				pthread_mutex_unlock(&(simulation->state_mutex));
				return (true);
			}
		}
		pthread_mutex_unlock(&(simulation->state_mutex));
	}
}


