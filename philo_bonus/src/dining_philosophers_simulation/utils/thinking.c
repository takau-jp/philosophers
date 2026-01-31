/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/23 16:39:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	take_a_fork(\
			t_simulation *simulation, t_philo *philo, pthread_mutex_t *fork);
bool	take_forks(t_simulation *simulation, t_philo *philo, \
			pthread_mutex_t *first_fork, pthread_mutex_t *second_fork);

bool	initial_thinking(\
			t_simulation *simulation, t_philo *philo, bool is_break_turn)
{
	t_timestamp	now;
	int64_t		break_time;

	if (logger(simulation, philo, &now, MSG_THINK) == false)
		return (false);
	break_time = 0;
	if (is_break_turn == true && philo->id == 2)
		break_time = simulation->time_to_eat * 1.5;
	else if (is_break_turn == true && philo->id == 1)
		break_time = simulation->time_to_eat;
	else if (philo->id % 2 == 0)
		break_time = simulation->time_to_eat / 2;
	if (break_time > 0)
	{
		if (smart_sleep(philo->last_meal.timeval, break_time, \
				simulation->time_to_die) == false)
		{
			return (false);
		}
	}
	if (philo->right == philo->left)
		return (take_a_fork(simulation, philo, philo->right));
	if (philo->left > philo->right)
		return (take_forks(simulation, philo, philo->left, philo->right));
	return (take_forks(simulation, philo, philo->right, philo->left));
}

bool	take_a_fork(\
			t_simulation *simulation, t_philo *philo, pthread_mutex_t *fork)
{
	t_timestamp	now;

	pthread_mutex_lock(fork);
	if (logger(simulation, philo, &now, MSG_FORK) == false)
	{
		pthread_mutex_unlock(fork);
		return (false);
	}
	smart_sleep(philo->last_meal.timeval, \
		simulation->time_to_die, simulation->time_to_die);
	pthread_mutex_unlock(fork);
	return (false);
}

bool	thinking(t_simulation *simulation, t_philo *philo, bool is_break_turn)
{
	t_timestamp	now;

	if (logger(simulation, philo, &now, MSG_THINK) == false)
		return (false);
	if (is_break_turn == true)
	{
		if (smart_sleep(philo->last_meal.timeval, \
				simulation->time_to_eat * 2.5, \
				simulation->time_to_die) == false)
		{
			return (false);
		}
	}
	if (philo->left > philo->right)
		return (take_forks(simulation, philo, philo->left, philo->right));
	return (take_forks(simulation, philo, philo->right, philo->left));
}

bool	take_forks(t_simulation *simulation, t_philo *philo, \
			pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	t_timestamp	now;

	pthread_mutex_lock(first_fork);
	if (logger(simulation, philo, &now, MSG_FORK) == false)
	{
		pthread_mutex_unlock(first_fork);
		return (false);
	}
	pthread_mutex_lock(second_fork);
	if (logger(simulation, philo, &now, MSG_FORK) == false)
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return (false);
	}
	return (true);
}
