/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philosophers_simulation.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:16:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINING_PHILOSOPHERS_SIMULATION_H
# define DINING_PHILOSOPHERS_SIMULATION_H

# define MSG_THINK "is thinking"
# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_DIED "died"


bool		simulate_dining_philosophers(t_simulation *simulation, \
	pid_t *philo_pids, t_philo *philos);
void		philo_routine(t_simulation *simulation, t_philo *philo);
bool		thinking(t_simulation *simualation, t_philo *philo);
bool		eating(t_simulation *simualation, t_philo *philo);
bool		sleeping(t_simulation *simualation, t_philo *philo);
void		*death_monitor_routine(void *arg);
t_timestamp	get_timestamp(struct timeval base);
bool		smart_sleep(\
				struct timeval base, int64_t ms_time, int64_t time_to_die);
bool		has_time_elapsed(struct timeval base, int64_t ms_time);
bool		logger(t_simulation *simulation, t_philo *philo, \
				t_timestamp *timestamp, char *msg);
bool		print_log(int64_t timestamp, int philo_id, char *msg);
void		waiter_routine(t_simulation *simulation, t_philo *philos);
void		eat_count_monitor_routine(t_simulation *simulation);


#endif
