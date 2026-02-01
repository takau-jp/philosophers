/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 22:40:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

void	cleanup(t_simulation *simulation, pid_t *philo_pids, t_philo *philos);
void	cleanup_simulation(t_simulation *simulation);
void	cleanup_philos(t_philo *philos, int number_of_philos);
void	cleanup_philo(t_philo *philo, int index);
void	clear_for_child_process(\
	t_simulation *simulation, pid_t *philo_pids, t_philo *philos);
void	clear_simulation(t_simulation *simulation);
void	clear_philos(t_philo *philos, int number_of_philos);
	
#endif
