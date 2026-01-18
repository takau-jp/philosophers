/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:22:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/18 22:03:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_ctx(t_ctx *ctx, t_settings *settings, t_simulation *simulation)
{
	if (init_forks(ctx, settings->n_philos) == false)
		return (false);
	if (init_philos(ctx, settings, simulation) == false)
	{
		clear_ctx(ctx, settings->n_philos);
		return (false);
	}
	return (true);
}





