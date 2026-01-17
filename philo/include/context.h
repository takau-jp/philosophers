/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:56:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:32:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

bool	init_ctx(t_ctx *ctx, t_settings *settings, t_simulation *simulation);
bool	init_forks(t_ctx *ctx, int n_philos);
bool	init_philos(t_ctx *ctx, t_settings *settings, t_simulation *simulation);
bool	init_pthread_retvals(t_ctx *ctx, int n_philos);
void	clear_ctx(t_ctx *ctx, int n_philos);

#endif