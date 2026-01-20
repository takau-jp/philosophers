/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:47:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 00:08:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	start_sleeping(t_philo *philo);

bool	sleeping(t_philo *philo)
{
	if (start_sleeping(philo) == false)
		return (false);
	usleep(philo->settings->time_to_sleep * 1000);
	return (true);
}

bool	start_sleeping(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(&(philo->simulation->simulation_mutex));
	if (philo->simulation->state != STATE_GOING)
	{
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		return (false);
	}
	timestamp = get_timestamp(philo->simulation->start);
	if (timestamp < 0)
	{
		philo->is_error = true;
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		return (false);
	}
	if (print_log(timestamp, philo->id, MSG_SLEEP) == false)
	{
		philo->is_error = true;
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		return (false);
	}
	pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	return (true);
}
