/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:16:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:35:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	wait_start(t_philo *philo)
{
	pthread_mutex_lock(&(philo->simulation->state_mutex));
	if (philo->simulation->state != STATE_GOING)
	{
		pthread_mutex_unlock(&(philo->simulation->state_mutex));
		return (false);
	}
	pthread_mutex_unlock(&(philo->simulation->state_mutex));
	return (true);
}
