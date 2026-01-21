/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:47:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 10:51:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	start_eating(t_philo *philo);
bool	end_eating(t_philo *philo);

bool	eating(t_philo *philo)
{
	if (start_eating(philo) == false)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (false);
	}
	if (smart_sleep(philo, philo->settings->time_to_eat) == false)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (false);
	}
	if (end_eating(philo) == false)
		return (false);
	return (true);
}

bool	start_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->simulation->simulation_mutex));
	if (philo->simulation->state != STATE_GOING)
	{
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		return (false);
	}
	philo->last_meal_timestamp = get_timestamp(philo->simulation->start);
	if (philo->last_meal_timestamp < 0)
	{
		philo->is_error = true;
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		return (false);
	}
	// if (print_log(philo->last_meal_timestamp, philo->id, MSG_EAT) == false)
	// {
	// 	philo->is_error = true;
	// 	pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	// 	return (false);
	// }
	pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	return (true);
}

bool	end_eating(t_philo *philo)
{
	if (philo->settings->must_eat_counts > 0)
	{
		pthread_mutex_lock(&(philo->simulation->simulation_mutex));
		if (philo->simulation->state != STATE_GOING)
		{
			pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
			pthread_mutex_unlock(philo->right);
			pthread_mutex_unlock(philo->left);
			return (false);
		}
		philo->eat_count++;
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
	}
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	return (true);
}
