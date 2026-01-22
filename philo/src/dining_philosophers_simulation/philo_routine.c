/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:54:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 16:15:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	t_simulation	*simulation;

	philo = (t_philo *)arg;
	simulation = philo->simulation;
	pthread_mutex_lock(&(simulation->state_mutex));
	philo->last_meal.timeval = simulation->start;
	philo->last_meal.timestamp = 0;
	pthread_mutex_unlock(&(simulation->state_mutex));
	if (initial_thinking(simulation, philo) == false)
		return (NULL);
	while (true)
	{
		if (eating(simulation, philo) == false)
			break ;
		if (sleeping(simulation, philo) == false)
			break ;
		if (thinking(simulation, philo) == false)
			break ;
	}
	return (NULL);
}
