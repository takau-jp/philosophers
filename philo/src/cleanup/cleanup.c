/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:10:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 00:03:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_forks(int n_philos, pthread_mutex_t *forks);
void	cleanup_philos(t_philo *philos);
void	cleanup_simulation_mutex(t_simulation *simulation);

void	cleanup(int n_philos, \
			pthread_mutex_t *forks, t_philo *philos, t_simulation *simulation)
{
	if (forks != NULL)
		cleanup_forks(n_philos, forks);
	if (philos != NULL)
		cleanup_philos(philos);
	if (simulation != NULL)
		cleanup_simulation_mutex(simulation);
}

void	cleanup_forks(int n_philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_destroy(&(forks[i]));
		i++;
	}
	free(forks);
}

void	cleanup_philos(t_philo *philos)
{
	free(philos);
}

void	cleanup_simulation_mutex(t_simulation *simulation)
{
	pthread_mutex_destroy(&(simulation->simulation_mutex));
}
