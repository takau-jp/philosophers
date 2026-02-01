/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:47:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 01:29:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sleeping(t_simulation *simulation, t_philo *philo)
{
	t_timestamp	now;

	if (logger(simulation, philo, &now, MSG_SLEEP) == false)
		return (false);
	return (smart_sleep(now.timeval, simulation->time_to_sleep, \
		simulation->time_to_die - simulation->time_to_eat));
}
