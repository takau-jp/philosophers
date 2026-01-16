/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/16 22:19:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_mutex_data(t_ctx *ctx)
{
	if (pthread_mutex_init(&(ctx->monitor_mutex), NULL) != 0)
	{
		print_error(ERROR_MSG_INIT_MUTEX);
		return (false);
	}
	// ctx->monitor_mutex = PTHREAD_MUTEX_INITIALIZER;
	if (pthread_mutex_init(&(ctx->print_mutex), NULL) != 0)
	{
		pthread_mutex_destroy(&(ctx->monitor_mutex));
		print_error(ERROR_MSG_INIT_MUTEX);
		return (false);
	}
	return (true);
}
