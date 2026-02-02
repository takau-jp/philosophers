/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:19:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 16:52:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_routine(t_simulation *simulation, t_philo *philo)
{
	pthread_t		pthread;
	t_pthread_arg	arg;

	arg.simulation = simulation;
	arg.philo = philo;
	if (pthread_create(&pthread, NULL, death_monitor_routine, &arg) != 0)
	{
		sem_wait(simulation->simulation_sem);
		sem_post(simulation->end_sem);
		print_error_log(ERROR_MSG_CREATE_PTHREAD);
		return ;
	}
	while (true)
	{
		if (thinking(simulation, philo) == false)
			break ;
		if (eating(simulation, philo) == false)
			break ;
		if (sleeping(simulation, philo) == false)
			break ;
	}
	pthread_join(pthread, NULL);
}
