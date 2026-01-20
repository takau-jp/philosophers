/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:59:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/20 01:39:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_log(int64_t timestamp, int philo_id, char *msg)
{
	if (printf("%" PRId64 " %d %s\n", timestamp, philo_id, msg) < 0)
		return (false);
	return (true);
}
