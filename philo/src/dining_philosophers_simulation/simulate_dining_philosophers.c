/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_dining_philosophers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 00:09:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_threads(int n_philos, t_philo *philos, t_simulation *simulation);
bool	start_simulation(t_simulation *simulation);
void	join_threads(int n_philos, t_philo *philos);

bool	simulate_dining_philosophers(\
			t_settings settings, t_philo *philos, t_simulation *simulation)
{
	pthread_mutex_lock(&(simulation->simulation_mutex));
	if (create_threads(settings.n_philos, philos, simulation) == false)
		return (false);
	if (start_simulation(simulation) == false)
	{
		join_threads(settings.n_philos, philos);
		return (false);
	}
	monitor_philos(settings, philos, simulation);
	join_threads(settings.n_philos, philos);
	if (simulation->state == STATE_ERROR)
		return (false);
	return (true);
}

bool	create_threads(int n_philos, t_philo *philos, t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		if (pthread_create(&(philos[i].thread), NULL, \
							philo_routine, &(philos[i])) != 0)
		{
			print_error_log(ERROR_MSG_CREATE_PTHREAD);
			simulation->state = STATE_ERROR;
			pthread_mutex_unlock(&(simulation->simulation_mutex));
			while (i-- > 0)
				pthread_join(philos[i].thread, NULL);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	start_simulation(t_simulation *simulation)
{
	if (gettimeofday(&(simulation->start), NULL) != 0)
	{
		print_error_log(ERROR_MSG_GET_TIMEOFDAY);
		simulation->state = STATE_ERROR;
		pthread_mutex_unlock(&(simulation->simulation_mutex));
		return (false);
	}
	simulation->state = STATE_GOING;
	pthread_mutex_unlock(&(simulation->simulation_mutex));
	return (true);
}

void	join_threads(int n_philos, t_philo *philos)
{
	int		i;

	i = 0;
	while (i < n_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
