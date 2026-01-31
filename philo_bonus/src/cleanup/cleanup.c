/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:18:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 22:48:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup(\
	t_simulation *simulation, t_philo_pid *pids, t_philo *philos)
{
	cleanup_semaphore(simulation);
	if (pids != NULL)
		free(pids);
	if (philos != NULL)
		cleanup_philos(philos, simulation->number_of_philos);
}
