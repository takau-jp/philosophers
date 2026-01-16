/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:22:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/16 17:03:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_ctx(t_ctx *ctx)
{
	if (init_mutex_data(ctx) == false)
		return (false);
	if (init_forks(ctx) == false)
	{
		clear_ctx(ctx);
		return (false);
	}
	if (init_philos(ctx) == false)
	{
		clear_ctx(ctx);
		return (false);
	}
	if (init_pthread_retvals(ctx) == false)
	{
		clear_ctx(ctx);
		return (false);
	}
	if (init_start_time(ctx) == false)
	{
		clear_ctx(ctx);
		return (false);
	}
	return (true);
}





