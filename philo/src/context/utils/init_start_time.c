/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:53:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/16 16:54:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_start_time(t_ctx *ctx)
{
	if (gettimeofday(&(ctx->start_time), NULL) != 0)
	{
		print_error(ERROR_MSG_GET_TIMEOFDAY);
		return (false);
	}
	return (true);
}
