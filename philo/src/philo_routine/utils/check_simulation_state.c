/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation_state.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:02:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/18 19:03:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_simulation_state(t_philo *philo)
{
	pthread_mutex_lock(&(philo->simulation->state_mutex));
	if (philo->simulation->state != STATE_GOING)
	{
		pthread_mutex_unlock(&(philo->simulation->state_mutex));
		return (false);
	}
	pthread_mutex_unlock(&(philo->simulation->state_mutex));
	return (true);
}


