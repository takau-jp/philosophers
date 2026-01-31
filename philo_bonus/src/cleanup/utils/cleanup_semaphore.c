/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_semaphore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:44:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 22:12:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup_semaphore(t_simulation *simulation)
{
	sem_close(simulation->fork_sem);
	sem_unlink(simulation->fork_sem);
	sem_close(simulation->log_sem);
	sem_unlink(simulation->log_sem);
	if (simulation->must_eat_counts != NO_EAT_LIMIT)
	{
		sem_close(simulation->eat_count_sem);
		sem_unlink(simulation->eat_count_sem);
	}
}
