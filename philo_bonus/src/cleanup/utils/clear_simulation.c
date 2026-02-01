/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:42:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 21:07:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clear_simulation(t_simulation *simulation)
{
	sem_close(simulation->fork_sem);
	sem_close(simulation->simulation_sem);
	sem_close(simulation->end_sem);
	if (simulation->must_eat_counts != NO_EAT_LIMIT)
	{
		sem_close(simulation->eat_count_sem);
	}
}
