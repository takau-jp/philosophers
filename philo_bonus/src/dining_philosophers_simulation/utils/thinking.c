/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:33:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 19:53:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	thinking(t_simulation *simualation, t_philo *philo)
{
	t_timestamp	now;

	if (logger(simualation, philo, &now, MSG_THINK) == false)
		return (false);
	sem_wait(philo->access_sem);
	sem_wait(simualation->fork_sem);
	sem_post(philo->used_access_sem);
	if (logger(simualation, philo, &now, MSG_FORK) == false)
		return (false);
	sem_wait(philo->access_sem);
	sem_wait(simualation->fork_sem);
	sem_post(philo->used_access_sem);
	if (logger(simualation, philo, &now, MSG_FORK) == false)
		return (false);
	return (true);
}
