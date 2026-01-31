/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:24:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/30 15:28:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool			initialize_state_mutex(t_simulation *simulation);
pthread_mutex_t	*initialize_forks(int number_of_philos);
t_philo			*initialize_philos(\
	t_simulation *simulation, pthread_mutex_t *forks);

bool	initialize(\
	t_simulation *simulation, pthread_mutex_t **forks, t_philo **philos)
{
	if (initialize_state_mutex(simulation) == false)
	{
		return (false);
	}
	*forks = initialize_forks(simulation->number_of_philos);
	if (*forks == NULL)
	{
		cleanup(simulation, NULL, NULL);
		return (false);
	}
	*philos = initialize_philos(simulation, *forks);
	if (*philos == NULL)
	{
		cleanup(simulation, *forks, NULL);
		return (false);
	}
	return (true);
}

bool	initialize_state_mutex(t_simulation *simulation)
{
	if (pthread_mutex_init(&(simulation->state_mutex), NULL) != 0)
	{
		print_error_log(ERROR_MSG_INIT_MUTEX);
		return (false);
	}
	return (true);
}

pthread_mutex_t	*initialize_forks(int number_of_philos)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)malloc(\
				sizeof(pthread_mutex_t) * number_of_philos);
	if (forks == NULL)
	{
		print_error_log(ERROR_MSG_MALLOC);
		return (NULL);
	}
	i = 0;
	while (i < number_of_philos)
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

t_philo	*initialize_philos(t_simulation *simulation, pthread_mutex_t *forks)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * simulation->number_of_philos);
	if (philos == NULL)
	{
		print_error_log(ERROR_MSG_MALLOC);
		return (NULL);
	}
	i = 0;
	while (i < simulation->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].right = &(forks[i]);
		philos[i].left = &(forks[(i + 1) % simulation->number_of_philos]);
		philos[i].simulation = simulation;
		philos[i].last_meal.timestamp = -1;
		philos[i].eat_count = 0;
		philos[i].is_error = false;
		i++;
	}
	return (philos);
}
