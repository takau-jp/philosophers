/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pthread_retvals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:51:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:32:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_pthread_retvals(t_ctx *ctx, int n_philos)
{
	ctx->pthread_retvals = (void **)malloc(sizeof(void *) * n_philos);
	if (ctx->pthread_retvals == NULL)
	{
		print_error(ERROR_MSG_MALLOC);
		return (false);
	}
	return (true);
}