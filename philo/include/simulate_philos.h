/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_philos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:30:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:33:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_PHILOS_H
# define SIMULATE_PHILOS_H

bool	init_simulation_mutex(t_simulation *simulation);
bool	create_threads(t_ctx *ctx, int n_philos, t_simulation *simulation);
void	join_threads(t_ctx *ctx, int n_philos);
bool	simulate_philos(t_ctx *ctx, int n_philos, t_simulation *simulation);
bool	start_simulation(t_simulation *simulation);

#endif