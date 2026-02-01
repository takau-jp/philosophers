/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:41:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	initialize(\
	t_simulation *simulation, pid_t **philo_pids, t_philo **philos)
{
	if (initialize_simulation(simulation) == false)
		return (false);
	*philo_pids = ft_calloc(simulation->number_of_philos, sizeof(pid_t));
	if (*philo_pids == NULL)
	{
		cleanup(simulation, NULL, NULL);
		return (false);
	}
	if (initialize_philos(philos, simulation->number_of_philos) == false)
	{
		cleanup(simulation, *philo_pids, NULL);
		return (false);
	}
	return (true);
}
