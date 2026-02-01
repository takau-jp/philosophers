/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:18:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 01:03:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup(t_simulation *simulation, t_pids *pids, t_philo *philos)
{
	cleanup_simulation(simulation);
	if (pids->philos != NULL)
		free(pids->philos);
	if (philos != NULL)
		cleanup_philos(philos, simulation->number_of_philos);
}
