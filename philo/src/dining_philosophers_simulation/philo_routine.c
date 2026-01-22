/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:54:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 02:00:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->simulation->state_mutex));
	philo->last_meal.timeval = philo->simulation->start;
	philo->last_meal.timestamp = 0;
	pthread_mutex_unlock(&(philo->simulation->state_mutex));
	if (initial_thinking(philo) == false)
		return (NULL);
	while (true)
	{
		if (eating(philo) == false)
			break ;
		if (sleeping(philo) == false)
			break ;
		if (thinking(philo) == false)
			break ;
	}
	return (NULL);
}
