/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_semaphore.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:40:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 22:12:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	initialize_semaphore(t_simulation *simulation)
{
	simulation->fork_sem = sem_open("forks", \
		O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, simulation->number_of_philos);
	if (simulation->fork_sem == SEM_FAILED)
		return (false);
	simulation->log_sem \
		= sem_open("log", O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, 1);
	if (simulation->log_sem == SEM_FAILED)
	{
		sem_close(simulation->fork_sem);
		sem_unlink(simulation->fork_sem);
		return (false);
	}
	if (simulation->must_eat_counts == NO_EAT_LIMIT)
		return (true);
	simulation->eat_count_sem \
		= sem_open("eat_count", O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, 0);
	if (simulation->eat_count_sem == SEM_FAILED)
	{
		sem_close(simulation->fork_sem);
		sem_unlink(simulation->fork_sem);
		sem_close(simulation->log_sem);
		sem_unlink(simulation->log_sem);
		return (false);
	}
	return (true);
}

