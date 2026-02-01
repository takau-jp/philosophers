/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:12:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 14:56:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_timestamp	get_timestamp(struct timeval base)
{
	t_timestamp	now;
	int64_t		second;
	int64_t		micro_seccond;

	gettimeofday(&(now.timeval), NULL);
	second = now.timeval.tv_sec - base.tv_sec;
	micro_seccond = now.timeval.tv_usec - base.tv_usec;
	now.timestamp = (second * 1000) + (micro_seccond / 1000);
	return (now);
}
