/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:33:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:31:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	sleeping(t_simulation *simualation, t_philo *philo)
{
	t_timestamp	now;

	if (logger(simualation, philo, &now, MSG_SLEEP) == false)
		return (false);
	if (smart_sleep(now.timeval, simualation->time_to_sleep, \
			simualation->time_to_die - simualation->time_to_eat) == false)
	{
		return (false);
	}
	return (true);
}
