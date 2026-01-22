/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:47:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 17:19:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	end_eating(t_simulation *simulation, t_philo *philo);

bool	eating(t_simulation *simulation, t_philo *philo)
{
	if (logger(simulation, philo, &(philo->last_meal), MSG_EAT) == false)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (false);
	}
	if (smart_sleep(philo->last_meal.timeval, \
			simulation->time_to_eat, simulation->time_to_die) == false)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (false);
	}
	return (end_eating(simulation, philo));
}

bool	end_eating(t_simulation *simulation, t_philo *philo)
{
	if (philo->left > philo->right)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	else
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
	}
	if (simulation->must_eat_counts > 0)
	{
		pthread_mutex_lock(&(simulation->state_mutex));
		if (simulation->state != STATE_GOING)
		{
			pthread_mutex_unlock(&(simulation->state_mutex));
			return (false);
		}
		philo->eat_count++;
		pthread_mutex_unlock(&(simulation->state_mutex));
	}
	return (true);
}
