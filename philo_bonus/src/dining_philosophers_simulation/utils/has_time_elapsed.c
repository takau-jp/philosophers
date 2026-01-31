/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_time_elapsed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:42:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 14:56:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	has_time_elapsed(struct timeval base, int64_t ms_time)
{
	struct timeval	now;
	int64_t			elapsed_us;

	gettimeofday(&now, NULL);
	elapsed_us = (now.tv_sec - base.tv_sec) * 1000000 \
					+ (now.tv_usec - base.tv_usec);
	return (elapsed_us >= (ms_time * 1000));
}
