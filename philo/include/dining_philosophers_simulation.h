/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philosophers_simulation.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/21 10:26:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DININING_PHILOSOPHERS_SIMULATION_H
# define DININING_PHILOSOPHERS_SIMULATION_H

# define MSG_THINK "is thinking"
# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_DIED "died"

bool	simulate_dining_philosophers(\
			t_settings settings, t_philo *philos, t_simulation *simulation);
void	monitor_philos(\
			t_settings settings, t_philo *philos, t_simulation *simulation);
void	*philo_routine(void *arg);
bool	thinking(t_philo *philo);
bool	eating(t_philo *philo);
bool	sleeping(t_philo *philo);
int64_t	get_timestamp(struct timeval start);
bool	print_log(int64_t timestamp, int philo_id, char *msg);
bool	smart_sleep(t_philo *philo, int waitting_time);

#endif
