/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:47:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 13:29:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sleeping(t_philo *philo)
{
	t_timestamp	now;

	if (logger(philo, &now, MSG_SLEEP) == false)
		return (false);
	return (smart_sleep(now.timeval, \
		philo->settings->time_to_sleep, philo->settings->time_to_die));
}
