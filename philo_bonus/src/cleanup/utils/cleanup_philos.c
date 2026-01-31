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

void	cleanup_philos(\
	t_philo *philos, int number_of_philos)
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

void	cleanup_philo(t_philo philo, int index)
{
	char name[20];

	sem_close(philo->access_sem);
	sem_unlink(create_name(name, "access_", index));
	sem_close(philo->used_sem);
	sem_unlink(create_name(name, "used_", index));
	sem_close(philo->meal_time_sem);
	sem_unlink(create_name(name, "meal_time_", index));
}
