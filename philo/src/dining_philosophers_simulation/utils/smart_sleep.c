/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 02:25:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 01:27:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	smart_sleep(struct timeval base, int64_t ms_time, int64_t time_to_die)
{
	while (true)
	{
		if (has_time_elapsed(base, time_to_die) == true)
			return (false);
		if (has_time_elapsed(base, ms_time) == true)
			return (true);
		usleep(100);
	}
}
