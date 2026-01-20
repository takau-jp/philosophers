/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:17:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/20 23:55:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_settings		settings;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	t_simulation	simulation;

	if (parse_arguments(argc, argv, &settings) == false)
		return (EXIT_FAILURE);
	if (initialize(&settings, &forks, &philos, &simulation) == false)
		return (EXIT_FAILURE);
	if (simulate_dining_philosophers(settings, philos, &simulation) == false)
	{
		cleanup(settings.n_philos, forks, philos, &simulation);
		return (EXIT_FAILURE);
	}
	cleanup(settings.n_philos, forks, philos, &simulation);
	return (EXIT_SUCCESS);
}
