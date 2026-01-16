/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:56:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/16 16:58:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

bool	init_ctx(t_ctx *ctx);
bool	init_mutex_data(t_ctx *ctx);
bool	init_forks(t_ctx *ctx);
bool	init_philos(t_ctx *ctx);
bool	init_pthread_retvals(t_ctx *ctx);
bool	init_start_time(t_ctx *ctx);
void	clear_ctx(t_ctx *ctx);

#endif