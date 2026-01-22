/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:47:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 02:23:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	end_eating(t_philo *philo);

bool	eating(t_philo *philo)
{
	if (logger(philo, &(philo->last_meal), MSG_EAT) == false)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (false);
	}
	if (smart_sleep(philo->last_meal.timeval, \
		philo->settings->time_to_sleep, philo->settings->time_to_die) == false)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (false);
	}
	return (end_eating(philo));
}

bool	end_eating(t_philo *philo)
{
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	if (philo->settings->must_eat_counts > 0)
	{
		pthread_mutex_lock(&(philo->simulation->state_mutex));
		if (philo->simulation->state != STATE_GOING)
		{
			pthread_mutex_unlock(&(philo->simulation->state_mutex));
			return (false);
		}
		philo->eat_count++;
		pthread_mutex_unlock(&(philo->simulation->state_mutex));
	}
	return (true);
}
