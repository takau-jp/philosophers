/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_dining_philosophers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:59:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 01:09:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	run_simulation(\
	t_simulation *simulation, t_pids *pids, t_philo *philos);
bool	run_waiter(t_simulation *simulation, t_pids *pids, t_philo *philos);
bool	run_eat_count_monitor(\
	t_simulation *simulation, t_pids *pids, t_philo *philos);
void	kill_all_process(t_simulation *simulation, t_pids *pids);

bool	simulate_dining_philosophers(\
	t_simulation *simulation, t_pids *pids, t_philo *philos)
{
	if (run_simulation(simulation, pids, philos) == false)
	{
		kill_all_process(simulation, pids);
		return (false);
	}
	if (run_waiter(simulation, pids, philos) == false)
	{
		kill_all_process(simulation, pids);
		return (false);
	}
	if (simulation->must_eat_counts != NO_EAT_LIMIT)
	{
		if (run_eat_count_monitor(simulation, pids, philos) == false)
		{
			kill_all_process(simulation, pids);
			return (false);
		}
	}
	sem_wait(simulation->end_sem);
	kill_all_process(simulation, pids);
	return (true);
}

bool	run_simulation(\
	t_simulation *simulation, t_pids *pids, t_philo *philos)
{
	pid_t	pid;
	int		i;

	gettimeofday(&(simulation->start), NULL);
	i = 0;
	while (i < simulation->number_of_philos)
	{
		philos[i].last_meal.timeval = simulation->start;
		pid = fork();
		if (pid == -1)
		{
			print_error_log(ERROR_MSG_CREATE_PROCESS);
			return (false);
		}
		if (pid == 0)
		{
			philo_routine(simulation, &philos[i]);
			clear_for_child_process(simulation, pids, philos);
			exit(0);
		}
		pids->philos[i] = pid;
		i++;
	}
	return (true);
}

bool	run_waiter(t_simulation *simulation, t_pids *pids, t_philo *philos)
{
	pids->waiter = fork();
	if (pids->waiter == -1)
	{
		print_error_log(ERROR_MSG_CREATE_PROCESS);
		return (false);
	}
	if (pids->waiter == 0)
	{
		waiter_routine(simulation, philos);
		clear_for_child_process(simulation, pids, philos);
		exit(0);
	}
	return (true);
}

bool	run_eat_count_monitor(\
	t_simulation *simulation, t_pids *pids, t_philo *philos)
{
	pids->eat_count_monitor = fork();
	if (pids->eat_count_monitor == -1)
	{
		print_error_log(ERROR_MSG_CREATE_PROCESS);
		return (false);
	}
	if (pids->eat_count_monitor == 0)
	{
		eat_count_monitor_routine(simulation);
		clear_for_child_process(simulation, pids, philos);
		exit(0);
	}
	return (true);
}

void	kill_all_process(t_simulation *simulation, t_pids *pids)
{
	int	i;

	i = 0;
	while (i < simulation->number_of_philos)
	{
		if (pids->philos[i] > 0)
			kill(pids->philos[i], SIGTERM);
		i++;
	}
	if (pids->waiter > 0)
		kill(pids->waiter, SIGTERM);
	if (pids->eat_count_monitor > 0)
		kill(pids->eat_count_monitor, SIGTERM);
}
