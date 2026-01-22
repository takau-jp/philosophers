/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_dining_philosophers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 02:18:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_threads(int n_philos, t_philo *philos, t_simulation *simulation);
void	start_simulation(t_simulation *simulation);
void	join_threads(int n_philos, t_philo *philos);

bool	simulate_dining_philosophers(\
			t_settings settings, t_philo *philos, t_simulation *simulation)
{
	pthread_mutex_lock(&(simulation->state_mutex));
	simulation->state = STATE_READY;
	if (create_threads(settings.n_philos, philos, simulation) == false)
		return (false);
	start_simulation(simulation);
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
			pthread_mutex_unlock(&(simulation->state_mutex));
			while (i-- > 0)
				pthread_join(philos[i].thread, NULL);
			return (false);
		}
		i++;
	}
	return (true);
}

void	start_simulation(t_simulation *simulation)
{
	gettimeofday(&(simulation->start), NULL);
	simulation->state = STATE_GOING;
	pthread_mutex_unlock(&(simulation->state_mutex));
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
