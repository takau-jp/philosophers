/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:44:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 21:08:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup_simulation(t_simulation *simulation)
{
	if (simulation->fork_sem != SEM_FAILED)
	{
		sem_close(simulation->fork_sem);
		sem_unlink("fork");
	}
	if (simulation->simulation_sem != SEM_FAILED)
	{
		sem_close(simulation->simulation_sem);
		sem_unlink("simulation");
	}
	if (simulation->end_sem != SEM_FAILED)
	{
		sem_close(simulation->end_sem);
		sem_unlink("end");
	}
	if (simulation->must_eat_counts != NO_EAT_LIMIT)
	{
		if (simulation->eat_count_sem != SEM_FAILED)
		{
			sem_close(simulation->eat_count_sem);
			sem_unlink("eat_count");
		}
	}
}
