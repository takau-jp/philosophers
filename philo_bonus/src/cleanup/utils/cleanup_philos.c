/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_philos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:03:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 19:07:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup_philos(t_philo *philos, int number_of_philos)
{
	int	i;

	if (philos == NULL)
		return ;
	i = 0;
	while (i < number_of_philos)
	{
		cleanup_philo(&(philos[i]), i);
		i++;
	}
	free(philos);
}

void	cleanup_philo(t_philo *philo, int index)
{
	char	name[30];

	if (philo->access_sem != SEM_FAILED)
	{
		sem_close(philo->access_sem);
		create_name(name, "access_", index);
		sem_unlink(name);
	}
	if (philo->used_access_sem != SEM_FAILED)
	{
		sem_close(philo->used_access_sem);
		create_name(name, "access_used_", index);
		sem_unlink(name);
	}
}
