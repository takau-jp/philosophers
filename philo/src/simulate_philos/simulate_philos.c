/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:25:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:29:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	simulate_philos(t_ctx *ctx, int n_philos, t_simulation *simulation)
{
	if (init_simulation_mutex(simulation) == false)
		return (false);
	pthread_mutex_lock(&(simulation->state_mutex));
	if (create_threads(ctx, n_philos, simulation) == false)
		return (false);
	if (start_simulation(simulation) == false)
	{
		simulation->state = STATE_END;
		pthread_mutex_unlock(&(simulation->state_mutex));
		join_threads(ctx, n_philos);
		return (false);
	}
	join_threads(ctx, n_philos);
	return (true);
}
