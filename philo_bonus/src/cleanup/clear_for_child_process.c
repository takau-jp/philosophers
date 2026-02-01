/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_for_child_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:30:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 01:14:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clear_for_child_process(\
	t_simulation *simulation, t_pids *pids, t_philo *philos)
{
	clear_simulation(simulation);
	if (pids->philos != NULL)
		free(pids->philos);
	if (philos != NULL)
		clear_philos(philos, simulation->number_of_philos);
}
