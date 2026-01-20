/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:24:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 00:00:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*initialize_forks(int n_philos);
t_philo			*initialize_philos(\
	t_settings *settings, pthread_mutex_t *forks, t_simulation *simulation);
bool			initialize_simulation_mutex(t_simulation *simulation);

bool	initialize(t_settings *settings, \
			pthread_mutex_t **forks, t_philo **philos, t_simulation *simulation)
{
	*forks = initialize_forks(settings->n_philos);
	if (*forks == NULL)
	{
		return (false);
	}
	*philos = initialize_philos(settings, *forks, simulation);
	if (*philos == NULL)
	{
		cleanup(settings->n_philos, *forks, NULL, NULL);
		return (false);
	}
	if (initialize_simulation_mutex(simulation) == false)
	{
		cleanup(settings->n_philos, *forks, *philos, NULL);
		return (false);
	}
	return (true);
}

pthread_mutex_t	*initialize_forks(int n_philos)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_philos);
	if (forks == NULL)
	{
		print_error_log(ERROR_MSG_MALLOC);
		return (NULL);
	}
	i = 0;
	while (i < n_philos)
	{
		if (pthread_mutex_init(&(forks[i]), NULL) != 0)
		{
			print_error_log(ERROR_MSG_INIT_MUTEX);
			while (i-- > 0)
				pthread_mutex_destroy(&(forks[i]));
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_philo	*initialize_philos(\
	t_settings *settings, pthread_mutex_t *forks, t_simulation *simulation)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * settings->n_philos);
	if (philos == NULL)
	{
		print_error_log(ERROR_MSG_MALLOC);
		return (NULL);
	}
	i = 0;
	while (i < settings->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].right = &(forks[i]);
		philos[i].left = &(forks[(i + 1) % settings->n_philos]);
		philos[i].settings = settings;
		philos[i].simulation = simulation;
		philos[i].last_meal_timestamp = 0;
		philos[i].eat_count = 0;
		philos[i].is_error = false;
		i++;
	}
	return (philos);
}

bool	initialize_simulation_mutex(t_simulation *simulation)
{
	if (pthread_mutex_init(&(simulation->simulation_mutex), NULL) != 0)
	{
		print_error_log(ERROR_MSG_INIT_MUTEX);
		return (false);
	}
	simulation->state = STATE_READY;
	return (true);
}
