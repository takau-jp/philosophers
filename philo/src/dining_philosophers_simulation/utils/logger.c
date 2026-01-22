/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:59:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 13:35:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	logger(t_philo *philo, t_timestamp *timestamp, char *msg)
{
	pthread_mutex_lock(&(philo->simulation->state_mutex));
	if (philo->simulation->state != STATE_GOING \
		|| has_time_elapsed(philo->last_meal.timeval, \
								philo->settings->time_to_die) == true)
	{
		pthread_mutex_unlock(&(philo->simulation->state_mutex));
		return (false);
	}
	*timestamp = get_timestamp(philo->simulation->start);
	if (print_log(timestamp->timestamp, philo->id, msg) == false)
	{
		print_error_log(ERROR_MSG_PRINT_STDOUT);
		philo->is_error = true;
		pthread_mutex_unlock(&(philo->simulation->state_mutex));
		return (false);
	}
	pthread_mutex_unlock(&(philo->simulation->state_mutex));
	return (true);
}

bool	print_log(int64_t timestamp, int philo_id, char *msg)
{
	if (printf("%" PRId64 " %d %s\n", timestamp, philo_id, msg) < 0)
		return (false);
	return (true);
}
