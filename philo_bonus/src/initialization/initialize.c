/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 01:10:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	initialize(\
	t_simulation *simulation, t_pids *pids, t_philo **philos)
{
	if (initialize_simulation(simulation) == false)
		return (false);
	memset(pids, 0, sizeof(t_pids));
	pids->philos = ft_calloc(simulation->number_of_philos, sizeof(pid_t));
	if (pids->philos == NULL)
	{
		print_error_log(ERROR_MSG_MALLOC);
		cleanup(simulation, NULL, NULL);
		return (false);
	}
	if (initialize_philos(philos, simulation->number_of_philos) == false)
	{
		cleanup(simulation, pids, NULL);
		return (false);
	}
	return (true);
}
