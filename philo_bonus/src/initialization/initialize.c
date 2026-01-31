/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 14:47:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	initialize(t_simulation *simulation, t_philo_pid **philo_pid)
{
	simulation->fork_semaphore = sem_open("forks", \
		O_CREAT | OEXCL, S_IRWXU | S_IRWXG, simulation->number_of_philos);
}
