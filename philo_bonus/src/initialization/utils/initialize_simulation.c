/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:40:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 00:53:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	initialize_simulation(t_simulation *simulation)
{
	sem_unlink("fork");
	simulation->fork_sem = sem_open("fork", \
		O_CREAT, S_IRWXU | S_IRWXG, simulation->number_of_philos);
	sem_unlink("simulation");
	simulation->simulation_sem \
		= sem_open("simulation", O_CREAT, S_IRWXU | S_IRWXG, 1);
	sem_unlink("end");
	simulation->end_sem = sem_open("end", O_CREAT, S_IRWXU | S_IRWXG, 0);
	if (simulation->must_eat_counts != NO_EAT_LIMIT)
	{
		sem_unlink("eat_count");
		simulation->eat_count_sem \
			= sem_open("eat_count", O_CREAT, S_IRWXU | S_IRWXG, 0);
	}
	if (simulation->fork_sem == SEM_FAILED \
		|| simulation->simulation_sem == SEM_FAILED \
		|| simulation->end_sem == SEM_FAILED \
		|| (simulation->must_eat_counts != NO_EAT_LIMIT \
			&& simulation->eat_count_sem == SEM_FAILED))
	{
		print_error_log(ERROR_MSG_INIT_SEMAPHORE);
		cleanup_simulation(simulation);
		return (false);
	}
	return (true);
}
