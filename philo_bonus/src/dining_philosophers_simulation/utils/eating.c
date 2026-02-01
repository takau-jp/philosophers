/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:33:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:59:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	eating(t_simulation *simualation, t_philo *philo)
{
	if (logger(simualation, philo, &(philo->last_meal), MSG_EAT) == false)
		return (false);
	if (smart_sleep(philo->last_meal.timeval, simualation->time_to_eat, \
			simualation->time_to_die) == false)
	{
		return (false);
	}
	sem_post(simualation->fork_sem);
	sem_post(simualation->fork_sem);
	if (simualation->must_eat_counts != NO_EAT_LIMIT)
	{
		philo->eat_count++;
		if (philo->eat_count == simualation->must_eat_counts)
			sem_post(simualation->eat_count_sem);
	}
	return (true);
}
