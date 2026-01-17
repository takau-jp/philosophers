/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:25:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 23:05:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	simulate_philos(t_ctx *ctx, t_settings settings, t_simulation *simulation)
{
	if (init_simulation_mutex(simulation) == false)
		return (false);
	pthread_mutex_lock(&(simulation->state_mutex));
	if (create_threads(ctx, settings.n_philos, simulation) == false)
		return (false);
	if (start_simulation(simulation) == false)
	{
		simulation->state = STATE_ERROR;
		pthread_mutex_unlock(&(simulation->state_mutex));
		join_threads(ctx, settings.n_philos);
		return (false);
	}
	monitoring_philos(ctx, settings, simulation);
	join_threads(ctx, settings.n_philos);
	return (true);
}
