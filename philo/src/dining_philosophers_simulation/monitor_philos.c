/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:54:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 00:09:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo(t_settings settings, t_simulation *simulation, \
						t_philo *philo, bool *is_finish);

void	monitor_philos(\
			t_settings settings, t_philo *philos, t_simulation *simulation)
{
	bool	is_finish;
	int		i;

	while (true)
	{
		is_finish = true;
		if (settings.must_eat_counts == NO_EAT_LIMIT)
			is_finish = false;
		i = 0;
		while (i < settings.n_philos)
		{
			pthread_mutex_lock(&(simulation->simulation_mutex));
			check_philo(settings, simulation, &(philos[i]), &is_finish);
			if (is_finish == true && i == settings.n_philos - 1 \
				&& simulation->state == STATE_GOING)
			{
				simulation->state = STATE_END;
			}
			if (simulation->state != STATE_GOING)
			{
				pthread_mutex_unlock(&(simulation->simulation_mutex));
				return ;
			}
			pthread_mutex_unlock(&(simulation->simulation_mutex));
			i++;
		}
	}
}

void	check_philo(t_settings settings, t_simulation *simulation, \
						t_philo *philo, bool *is_finish)
{
	int64_t	timestamp;

	timestamp = get_timestamp(simulation->start);
	if (timestamp < 0)
	{
		simulation->state = STATE_ERROR;
	}
	else if (philo->is_error == true)
	{
		simulation->state = STATE_ERROR;
	}
	else if (settings.time_to_die <= timestamp - philo->last_meal_timestamp)
	{
		simulation->state = STATE_DEAD;
		print_log(timestamp, philo->id, MSG_DIED);
	}
	else if (settings.must_eat_counts > philo->eat_count)
	{
		*is_finish = false;
	}
}
