/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:17:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 15:48:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	t_simulation	simulation;

	if (parse_arguments(argc, argv, &simulation) == false)
		return (EXIT_FAILURE);
	if (initialize(&simulation, &forks, &philos) == false)
		return (EXIT_FAILURE);
	if (simulate_dining_philosophers(&simulation, philos) == false)
	{
		cleanup(&simulation, forks, philos);
		return (EXIT_FAILURE);
	}
	cleanup(&simulation, forks, philos);
	return (EXIT_SUCCESS);
}
