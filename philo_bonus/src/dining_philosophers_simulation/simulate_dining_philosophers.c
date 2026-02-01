/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_dining_philosophers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:59:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:39:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	run_simulation(t_simulation *simulation, \
	pid_t *philo_pids, t_philo *philos);
bool	run_waiter(pid_t *waiter_pid, t_simulation *simulation, \
	pid_t *philo_pids, t_philo *philos);
bool	run_eat_count_monitor(pid_t *eat_count_monitor_pid, \
	t_simulation *simulation, pid_t *philo_pids, t_philo *philos);
void	kill_all_process(t_simulation *simulation, pid_t *philo_pids, \
	pid_t waiter_pid, pid_t eat_count_monitor_pid);

bool	simulate_dining_philosophers(t_simulation *simulation, \
	pid_t *philo_pids, t_philo *philos)
{
	pid_t	waiter_pid;
	pid_t	eat_count_monitor_pid;
	
	waiter_pid = 0;
	eat_count_monitor_pid = 0;
	if (run_simulation(simulation, philo_pids, philos) == false)
	{
		kill_all_process(simulation, philo_pids, -1, -1);
		return (false);
	}
	if (run_waiter(&waiter_pid, simulation, philo_pids, philos) == false)
	{
		kill_all_process(simulation, philo_pids, -1, -1);
		return (false);
	}
	if (simulation->must_eat_counts != NO_EAT_LIMIT)
	{
		if (run_eat_count_monitor(&eat_count_monitor_pid, simulation, philo_pids, philos) == false)
		{
			kill_all_process(simulation, philo_pids, waiter_pid, -1);
			return (false);
		}
	}
	sem_wait(simulation->end_sem);
	kill_all_process(simulation, philo_pids, waiter_pid, eat_count_monitor_pid);
	return (true);
}

bool	run_simulation(t_simulation *simulation, \
	pid_t *philo_pids, t_philo *philos)
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
			philo_routine(simulation, &philos[i]);
		}
		philo_pids[i] = pid;
		i++;
	}
	return (true);
}

bool	run_waiter(pid_t *waiter_pid, t_simulation *simulation, \
	pid_t *philo_pids, t_philo *philos)
{
	*waiter_pid = fork();
	if (*waiter_pid == -1)
		return (false);
	if (*waiter_pid == 0)
	{
		waiter_routine(simulation, philos);
		clear_for_child_process(simulation, philo_pids, philos);
		exit(0);
	}
	return (true);
}

bool	run_eat_count_monitor(pid_t *eat_count_monitor_pid, t_simulation *simulation, \
	pid_t *philo_pids, t_philo *philos)
{
	*eat_count_monitor_pid = fork();
	if (*eat_count_monitor_pid == -1)
		return (false);
	if (*eat_count_monitor_pid == 0)
	{
		eat_count_monitor_routine(simulation);
		clear_for_child_process(simulation, philo_pids, philos);
		exit(0);
	}
	return (true);
}

void	kill_all_process(t_simulation *simulation, pid_t *philo_pids, \
	pid_t waiter_pid, pid_t eat_count_monitor_pid)
{
	int	i;

	i = 0;
	while (i < simulation->number_of_philos)
	{
		if (philo_pids[i] > 0)
			kill(philo_pids[i], SIGTERM);
		i++;
	}
	if (waiter_pid > 0)
		kill(waiter_pid, SIGTERM);
	if (eat_count_monitor_pid > 0)
		kill(eat_count_monitor_pid, SIGTERM);
}
