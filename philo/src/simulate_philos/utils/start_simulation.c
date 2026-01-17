/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:53:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 23:29:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	start_simulation(t_simulation *simulation)
{
	if (gettimeofday(&(simulation->start_time), NULL) != 0)
	{
		print_error(ERROR_MSG_GET_TIMEOFDAY);
		return (false);
	}
	simulation->state = STATE_GOING;
	simulation->finished_philos_count = 0;
	pthread_mutex_unlock(&(simulation->state_mutex));
	return (true);
}
