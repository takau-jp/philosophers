/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:12:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/20 23:46:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	get_timestamp(struct timeval start)
{
	struct timeval	now;
	int64_t			second;
	int64_t			micro_seccond;

	if (gettimeofday(&now, NULL) != 0)
	{
		print_error_log(ERROR_MSG_GET_TIMEOFDAY);
		return (-1);
	}
	second = now.tv_sec - start.tv_sec;
	micro_seccond = now.tv_usec - start.tv_usec;
	return (second * 1000 + micro_seccond / 1000);
}
