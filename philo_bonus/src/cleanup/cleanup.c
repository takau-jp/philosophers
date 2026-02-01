/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:18:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 15:56:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup(t_simulation *simulation, pid_t *philo_pids, t_philo *philos)
{
	cleanup_simulation(simulation);
	if (philo_pids != NULL)
		free(philo_pids);
	if (philos != NULL)
		cleanup_philos(philos, simulation->number_of_philos);
}
