/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:07:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/03 12:33:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	initialize_philo(t_philo *philo, int index);

bool	initialize_philos(t_philo **philos, int number_of_philos)
{
	int	i;

	*philos = ft_calloc(number_of_philos, sizeof(t_philo));
	if (*philos == NULL)
	{
		print_error_log(ERROR_MSG_MALLOC);
		return (false);
	}
	i = 0;
	while (i < number_of_philos)
	{
		(*philos)[i].id = i + 1;
		if (initialize_philo(&((*philos)[i]), i) == false)
		{
			while (i-- > 0)
				cleanup_philo(&((*philos)[i]), i);
			free(*philos);
			*philos = NULL;
			return (false);
		}
		i++;
	}
	return (true);
}

bool	initialize_philo(t_philo *philo, int index)
{
	char	name[30];

	create_name(name, "access_", index);
	sem_unlink(name);
	philo->access_sem = sem_open(name, O_CREAT, S_IRWXU | S_IRWXG, 0);
	create_name(name, "access_used_", index);
	sem_unlink(name);
	philo->used_access_sem = sem_open(name, O_CREAT, S_IRWXU | S_IRWXG, 0);
	if (philo->access_sem == SEM_FAILED || philo->used_access_sem == SEM_FAILED)
	{
		print_error_log(ERROR_MSG_INIT_SEMAPHORE);
		cleanup_philo(philo, index);
		return (false);
	}
	return (true);
}
