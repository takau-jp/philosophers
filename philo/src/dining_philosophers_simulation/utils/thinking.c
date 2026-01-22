/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 14:57:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	take_a_fork(t_philo *philo, pthread_mutex_t *fork);
bool	take_forks(t_philo *philo, \
			pthread_mutex_t *first_fork, pthread_mutex_t *second_fork);

bool	initial_thinking(t_philo *philo)
{
	t_timestamp	now;

	if (logger(philo, &now, MSG_THINK) == false)
		return (false);
	if (philo->id % 2 == 0)
	{
		if (smart_sleep(philo->simulation->start, \
			philo->settings->time_to_eat / 2, \
			philo->settings->time_to_die) == false)
		{
			return (false);
		}
	}
	if (philo->right == philo->left)
		return (take_a_fork(philo, philo->right));
	if (philo->left < philo->right)
		return (take_forks(philo, philo->left, philo->right));
	return (take_forks(philo, philo->right, philo->left));
}

bool	take_a_fork(t_philo *philo, pthread_mutex_t *fork)
{
	t_timestamp	now;

	pthread_mutex_lock(fork);
	if (logger(philo, &now, MSG_FORK) == false)
	{
		pthread_mutex_unlock(fork);
		return (false);
	}
	smart_sleep(philo->last_meal.timeval, \
		philo->settings->time_to_die, philo->settings->time_to_die);
	pthread_mutex_unlock(fork);
	return (false);
}

bool	thinking(t_philo *philo)
{
	t_timestamp	now;

	if (logger(philo, &now, MSG_THINK) == false)
		return (false);
	if (philo->left < philo->right)
		return (take_forks(philo, philo->left, philo->right));
	return (take_forks(philo, philo->right, philo->left));
}

bool	take_forks(t_philo *philo, \
			pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	t_timestamp	now;

	pthread_mutex_lock(first_fork);
	if (logger(philo, &now, MSG_FORK) == false)
	{
		pthread_mutex_unlock(first_fork);
		return (false);
	}
	pthread_mutex_lock(second_fork);
	if (logger(philo, &now, MSG_FORK) == false)
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return (false);
	}
	return (true);
}
