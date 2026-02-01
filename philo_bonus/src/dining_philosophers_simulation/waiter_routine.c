/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:09:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 00:45:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	waiter_routine(t_simulation *simulation, t_philo *philos)
{
	int	i;
	int	fork_count;

	i = 0;
	fork_count = 0;
	while (true)
	{
		sem_wait(simulation->fork_sem);
		sem_post(simulation->fork_sem);
		sem_post(philos[i].access_sem);
		sem_wait(philos[i].used_access_sem);
		if (++fork_count < 2)
			continue ;
		fork_count = 0;
		i++;
		if (i == simulation->number_of_philos)
			i = 0;
	}
}
