/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 02:25:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 10:36:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	smart_sleep(t_philo *philo, int waitting_time)
{
	struct timeval	start;
	struct timeval	now;

	if (gettimeofday(&start, NULL) != 0)
	{
		pthread_mutex_lock(&(philo->simulation->simulation_mutex));
		philo->is_error = true;
		print_error_log(ERROR_MSG_GET_TIMEOFDAY);
		pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
		return (false);
	}
	while (true)
	{
		if (gettimeofday(&now, NULL) != 0)
		{
			pthread_mutex_lock(&(philo->simulation->simulation_mutex));
			philo->is_error = true;
			print_error_log(ERROR_MSG_GET_TIMEOFDAY);
			pthread_mutex_unlock(&(philo->simulation->simulation_mutex));
			return (false);
		}
		if ((int64_t)(now.tv_sec - start.tv_sec) * 1000 + (int64_t)(now.tv_usec - start.tv_usec) / 1000 \
				>= waitting_time)
		{
			return (true);
		}
		usleep(100);
	}
}
