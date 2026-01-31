/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_dining_philosophers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:59:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 00:06:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	simulate_dining_philosophers(t_simulation *simulation, \
	t_philo_pid *pids, t_philo *philos)
{
	pid_t	waiter_pid;
	pid_t	monitor_pid;
	
	waiter_pid = 0;
	monitor_pid = 0;
	if (run_simualtion(simulation, pids, philos) == false)
	{
		return (false);
	}
	if (run_waiter(&waiter_pid, simulation, pids, philos) == false)
	{
		return (false);
	}
	if (simulation->must_eat_counts != NO_EAT_LIMIT)
	{
		if (run_monitor(&waiter_pid, simulation, pids, philos) == false)
		{
			return (false);
		}
	}
	wait_simulation();
	kill_all_process(simulation, pids, waiter_pid, monitor_pid);
}

void	wait_simulation(void)
{
	int	status;

	if (wait(&status) == -1);
		printf("Error\n");
}

void	kill_all_process(t_simulation *simulation, t_philo_pid *pids, \
	pid_t waiter_pid, pid_t monitor_pid)
{
	int	i;

	i = 0;
	while (i < simulation->number_of_philos)
	{
		if (pids[i] > 0)
			kill(pids[i], SIGTERM);
		else
			break ;
		i++;
	}
	if (pids[i] > 0)
		kill(waiter_pid, SIGTERM);
	if (pids[i] > 0)
		kill(waiter_pid, SIGTERM);
}

bool	run_simulation(t_simulation *simulation, \
	t_philo_pid *pids, t_philo *philos)
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
			return (false);
		if (pid == 0)
		{
			free(pids);
			philo_routine(simulation, philos, i);
		}
		pids[i].id = philos[i].id;
		pids[i].pid = pid;
		i++;
	}
	return (true);
}

bool	run_waiter(pid_t *waiter_pid, t_simulation *simulation, \
	t_philo_pid *pids, t_philo *philos)
{
	*waiter_pid = fork();
	if (*waiter_pid == -1)
		return (false);
	if (*waiter_pid == 0)
	{
		free(pids);
		waiter_routine(simulation, philos);
	}
	return (true);
}

bool	run_monitor(pid_t *monitor_pid, t_simulation *simulation, \
	t_philo_pid *pids, t_philo *philos)
{
	*monitor_pid = fork();
	if (*monitor_pid == -1)
		return (false);
	if (*monitor_pid == 0)
	{
		free(pids);
		cleanup_philos(philos, simulation->number_of_philos);
		monitor_routine(simulation);
	}
	return (true);
}
