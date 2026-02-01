/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_count_monitor_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:10:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 15:23:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_count_monitor_routine(t_simulation *simulation)
{
	int	count;

	count = simulation->number_of_philos;
	while (count > 0)
	{
		sem_wait(simulation->eat_count_sem);
		count--;
	}
	sem_post(simulation->end_sem);
}
