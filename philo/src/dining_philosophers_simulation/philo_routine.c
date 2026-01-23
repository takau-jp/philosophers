/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:54:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/23 16:35:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_start(t_simulation *simulation, t_philo *philo);
void	initialize_break_turn_count(t_philo *philo, t_simulation *simulation, \
			int *break_turn_span, int *break_turn_count);
void	update_break_turn_count(int break_turn_span, int *break_turn_count);

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	t_simulation	*simulation;
	int				break_turn_span;
	int				break_turn_count;

	philo = (t_philo *)arg;
	simulation = philo->simulation;
	initialize_break_turn_count(\
		philo, simulation, &break_turn_span, &break_turn_count);
	wait_start(simulation, philo);
	if (initial_thinking(simulation, philo, break_turn_count == 0) == false)
		return (NULL);
	while (true)
	{
		if (eating(simulation, philo) == false)
			break ;
		if (sleeping(simulation, philo) == false)
			break ;
		update_break_turn_count(break_turn_span, &break_turn_count);
		if (thinking(simulation, philo, break_turn_count == 0) == false)
			break ;
	}
	return (NULL);
}

void	wait_start(t_simulation *simulation, t_philo *philo)
{
	pthread_mutex_lock(&(simulation->state_mutex));
	philo->last_meal.timeval = simulation->start;
	philo->last_meal.timestamp = 0;
	pthread_mutex_unlock(&(simulation->state_mutex));
}

void	initialize_break_turn_count(t_philo *philo, t_simulation *simulation, \
			int *break_turn_span, int *break_turn_count)
{
	*break_turn_span = simulation->n_philos / 2;
	if (simulation->n_philos % 2 == 1)
		*break_turn_count = (philo->id + 1) / 2 - 1;
	else
		*break_turn_count = NO_BREAK;
}

void	update_break_turn_count(int break_turn_span, int *break_turn_count)
{
	if (*break_turn_count == NO_BREAK)
		return ;
	if (*break_turn_count == 0)
		*break_turn_count = break_turn_span;
	*break_turn_count -= 1;
}
