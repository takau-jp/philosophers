/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:40:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:30:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_ctx *ctx, int n_philos)
{
	int		i;

	i = 0;
	while (i < n_philos)
	{
		pthread_join(ctx->philos[i].thread, NULL);
		i++;
	}
}
