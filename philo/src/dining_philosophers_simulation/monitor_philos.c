/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:54:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 15:26:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_until_next_ms(struct timeval clock);
bool	check_philos(\
			t_settings settings, t_philo *philos, t_simulation *simulation);
void	check_philo(t_settings settings, t_simulation *simulation, \
						t_philo *philo, bool *is_finish);

void	monitor_philos(\
			t_settings settings, t_philo *philos, t_simulation *simulation)
{
	struct timeval	clock;

	gettimeofday(&clock, NULL);
	wait_until_next_ms(clock);
	while (true)
	{
		gettimeofday(&clock, NULL);
		if (check_philos(settings, philos, simulation) == false)
			return ;
		wait_until_next_ms(clock);
	}
}

void	wait_until_next_ms(struct timeval clock)
{
	while (true)
	{
		if (has_time_elapsed(clock, 1) == true)
			return ;
		usleep(100);
	}
}

bool	check_philos(\
			t_settings settings, t_philo *philos, t_simulation *simulation)
{
	bool	is_finish;
	int		i;

	is_finish = true;
	if (settings.must_eat_counts == NO_EAT_LIMIT)
		is_finish = false;
	i = 0;
	while (i < settings.n_philos)
	{
		pthread_mutex_lock(&(simulation->state_mutex));
		check_philo(settings, simulation, &(philos[i]), &is_finish);
		if (is_finish == true && i == settings.n_philos - 1 \
			&& simulation->state == STATE_GOING)
		{
			simulation->state = STATE_END;
		}
		if (simulation->state != STATE_GOING)
		{
			pthread_mutex_unlock(&(simulation->state_mutex));
			return (false);
		}
		pthread_mutex_unlock(&(simulation->state_mutex));
		i++;
	}
	return (true);
}

void	check_philo(t_settings settings, t_simulation *simulation, \
						t_philo *philo, bool *is_finish)
{
	if (philo->last_meal.timestamp < 0)
	{
		*is_finish = false;
		return ;
	}
	if (philo->is_error == true)
	{
		simulation->state = STATE_ERROR;
		return ;
	}
	if (has_time_elapsed(philo->last_meal.timeval, settings.time_to_die))
	{
		simulation->state = STATE_DEAD;
		if (!print_log(\
			get_timestamp(simulation->start).timestamp, philo->id, MSG_DIED))
		{
			print_error_log(ERROR_MSG_PRINT_STDOUT);
		}
	}
	else if (settings.must_eat_counts > philo->eat_count)
	{
		*is_finish = false;
	}
}
