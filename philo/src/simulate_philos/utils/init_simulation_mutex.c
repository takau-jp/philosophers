/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 23:33:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_simulation_mutex(t_simulation *simulation)
{
	if (pthread_mutex_init(&(simulation->state_mutex), NULL) != 0)
	{
		print_error(ERROR_MSG_INIT_MUTEX);
		return (false);
	}
	// if (pthread_mutex_init(&(simulation->count_mutex), NULL) != 0)
	// {
	// 	pthread_mutex_destroy(&(simulation->state_mutex));
	// 	print_error(ERROR_MSG_INIT_MUTEX);
	// 	return (false);
	// }
	if (pthread_mutex_init(&(simulation->print_mutex), NULL) != 0)
	{
		pthread_mutex_destroy(&(simulation->state_mutex));
		// pthread_mutex_destroy(&(simulation->count_mutex));
		print_error(ERROR_MSG_INIT_MUTEX);
		return (false);
	}
	return (true);
}
