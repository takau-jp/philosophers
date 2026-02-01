/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:17:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:10:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	pid_t			*philo_pids;
	t_philo			*philos;

	if (parse_arguments(argc, argv, &simulation) == false)
		return (EXIT_FAILURE);
	if (initialize(&simulation, &philo_pids, &philos) == false)
		return (EXIT_FAILURE);
	if (simulate_dining_philosophers(&simulation, philo_pids, philos) == false)
	{
		cleanup(&simulation, philo_pids, philos);
		return (EXIT_FAILURE);
	}
	cleanup(&simulation, philo_pids, philos);
	return (EXIT_SUCCESS);
}
