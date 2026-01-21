/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 10:51:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	start_thinking(t_philo *philo);
bool	take_fork(t_philo *philo, pthread_mutex_t *fork);

bool	thinking(t_philo *philo)
{
	if (start_thinking(philo) == false)
		return (false);
	if (philo->id % 2 == 1)
	{
		if (take_fork(philo, philo->right) == false)
			return (false);
		if (take_fork(philo, philo->left) == false)
		{
			pthread_mutex_unlock(philo->right);
			return (false);
		}
	}
	else
	{
		if (take_fork(philo, philo->left) == false)
			return (false);
		if (take_fork(philo, philo->right) == false)
		{
			pthread_mutex_unlock(philo->left);
			return (false);
		}
	}
	return (true);
}

bool	start_thinking(t_philo *philo)
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
	// if (print_log(timestamp, philo->id, MSG_THINK) == false)
	// {
	// 	philo->is_error = true;
	// 	pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	// 	return (false);
	// }
	pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	return (true);
}

bool	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int64_t	timestamp;

	pthread_mutex_lock(fork);
	pthread_mutex_lock(&(philo->simulation->simulation_mutex));
	if (philo->simulation->state != STATE_GOING)
	{
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		pthread_mutex_unlock(fork);
		return (false);
	}
	timestamp = get_timestamp(philo->simulation->start);
	if (timestamp < 0)
	{
		philo->is_error = true;
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		pthread_mutex_unlock(fork);
		return (false);
	}
	// if (print_log(timestamp, philo->id, MSG_FORK) == false)
	// {
	// 	philo->is_error = true;
	// 	pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	// 	pthread_mutex_unlock(fork);
	// 	return (false);
	// }
	pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	return (true);
}
