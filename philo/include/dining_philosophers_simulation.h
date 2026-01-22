/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philosophers_simulation.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 02:24:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINING_PHILOSOPHERS_SIMULATION_H
# define DINING_PHILOSOPHERS_SIMULATION_H

# define MSG_THINK "is thinking"
# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_DIED "died"

bool		simulate_dining_philosophers(\
				t_settings settings, t_philo *philos, t_simulation *simulation);
void		monitor_philos(\
				t_settings settings, t_philo *philos, t_simulation *simulation);
void		*philo_routine(void *arg);
bool		initial_thinking(t_philo *philo);
bool		thinking(t_philo *philo);
bool		eating(t_philo *philo);
bool		sleeping(t_philo *philo);
t_timestamp	get_timestamp(struct timeval base);
bool		smart_sleep(\
				struct timeval base, int64_t ms_time, int64_t time_to_die);
bool		has_time_elapsed(struct timeval base, int64_t ms_time);
bool		logger(t_philo *philo, t_timestamp *timestamp, char *msg);
bool		print_log(int64_t timestamp, int philo_id, char *msg);

#endif
