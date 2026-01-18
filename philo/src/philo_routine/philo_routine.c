/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:05:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/18 22:14:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This philosopher only thinks about picking up a fork to eat and sleep.
void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (wait_start(philo) == false)
		return (NULL);
	while (true)
	{
		thinking();
		eating();
		sleeping();
	}
	return (NULL);
}

bool	thinking(t_philo *philo, int routine_count)
{
	if (print_thinking() == false)
		return (false);
	if (philo->settings->n_philos % 2 == 1)
	{
		if (philo->index == routine_count + 1)
		{
			if (pass_routine() == false)
				return (false);
		}
	}
	if (philo->index % 2 == 1)
	{
		if (take_fork() == false)
			return (false);
		if (take_fork() == false)
			return (false);
	}
	else
	{
		if (take_fork() == false)
			return (false);
		if (take_fork() == false)
			return (false);
	}
	return (true);
}
