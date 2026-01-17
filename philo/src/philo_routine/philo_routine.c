/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:05:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 23:55:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (wait_start(philo) == false)
		return (NULL);
	while (true)
	{
		if (check_simulation_state(philo) == false)
			break ;
		
	}
	return (NULL);
}

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
