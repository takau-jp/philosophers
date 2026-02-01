/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:56:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 00:50:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_until_next_ms(struct timeval clock);

void	*death_monitor_routine(void *arg)
{
	struct timeval	clock;
	t_simulation	*simulation;
	t_philo			*philo;

	simulation = ((t_pthread_arg *)arg)->simulation;
	philo = ((t_pthread_arg *)arg)->philo;
	while (true)
	{
		gettimeofday(&clock, NULL);
		sem_wait(simulation->simulation_sem);
		if (has_time_elapsed(philo->last_meal.timeval, simulation->time_to_die))
		{
			if (print_log(get_timestamp(simulation->start).timestamp, \
					philo->id, MSG_DIED) == false)
			{
				print_error_log(ERROR_MSG_PRINT_STDOUT);
			}
			sem_post(simulation->end_sem);
			return (NULL);
		}
		sem_post(simulation->simulation_sem);
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
