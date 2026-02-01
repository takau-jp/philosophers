/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 01:03:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

bool	initialize(\
	t_simulation *simulation, t_pids *pids, t_philo **philos);
bool	initialize_simulation(t_simulation *simulation);
bool	initialize_philos(t_philo **philos, int number_of_philos);

#endif
