/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:07:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 22:11:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool initialize_philo_semaphore(t_philo philo, int index);

bool initialize_philos(
	t_philo **philos, int number_of_philos)
{
	t_philo *philo;
	int i;

	*philos = ft_calloc(number_of_philos, sizeof(t_philo));
	if (*philos == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_philos)
	{
		philo = &((*philos)[i]);
		philo->id = i + 1;
		if (initialize_philo_semaphore(philo, i) == false)
		{
			while (i-- > 0)
			{
				philo = &((*philos)[i]);
				cleanup_philo(philo, i);
			}
			free(*philos);
			*philos = NULL;
			return (false);
		}
		i++;
	}
	return (true);
}

bool initialize_philo_semaphore(t_philo *philo, int index)
{
	char name[20];

	philo->access_sem = sem_open(create_name(name, "access_", index), \
							O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, 0);
	if (philo->access_sem == SEM_FAILED)
		return (false);
	philo->used_sem = sem_open(create_name(name, "used_", index), \
							O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, 0);
	if (philo->used_sem == SEM_FAILED)
	{
		sem_close(philo->access_sem);
		sem_unlink(create_name(name, "access_", index));
		return (false);
	}
	philo->meal_time_sem = sem_open(create_name(name, "meal_time_", index), \
							O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, 0);
	if (philo->used_sem == SEM_FAILED)
	{
		sem_close(philo->access_sem);
		sem_unlink(create_name(name, "access_", index));
		sem_close(philo->used_sem);
		sem_unlink(create_name(name, "used_", index));
		return (false);
	}
	return (true);
}
