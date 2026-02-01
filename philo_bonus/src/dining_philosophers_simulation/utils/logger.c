/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:59:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 23:30:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	logger(t_simulation *simulation, t_philo *philo, \
				t_timestamp *now, char *msg)
{
	sem_wait(simulation->simulation_sem);
	*now = get_timestamp(simulation->start);
	if (print_log(now->timestamp, philo->id, msg) == false)
	{
		print_error_log(ERROR_MSG_PRINT_STDOUT);
		sem_post(simulation->end_sem);
		return (false);
	}
	sem_post(simulation->simulation_sem);
	return (true);
}

bool	print_log(int64_t timestamp, int philo_id, char *msg)
{
	if (printf("%" PRId64 " %d %s\n", timestamp, philo_id, msg) < 0)
		return (false);
	return (true);
}
