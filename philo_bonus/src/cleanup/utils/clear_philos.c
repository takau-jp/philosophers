/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:42:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:38:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clear_philos(\
	t_philo *philos, int number_of_philos)
{
	int	i;

	if (philos == NULL)
		return ;
	i = 0;
	while (i < number_of_philos)
	{
		sem_close(philos[i].access_sem);
		sem_close(philos[i].used_access_sem);
		i++;
	}
	free(philos);
}
