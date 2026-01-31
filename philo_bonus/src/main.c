/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:17:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/30 17:16:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philo_pid		*philo_pid;

	if (parse_arguments(argc, argv, &simulation) == false)
		return (EXIT_FAILURE);
	if (initialize(&simulation, &philo_pid) == false)
		return (EXIT_FAILURE);
	if (simulate_dining_philosophers(&simulation, philos) == false)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
