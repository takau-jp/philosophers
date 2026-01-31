/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 21:58:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	initialize(t_simulation *simulation, \
	t_philo_pid **pids, t_philo **philos)
{
	if (initialize_semaphore(simulation) == false)
		return (false);
	*pids = ft_calloc(simulation->number_of_philos, sizeof(t_philo_pid));
	if (*pids == NULL)
	{
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
