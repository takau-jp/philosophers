/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:51:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/15 15:46:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_int(char *str)
{
	int64_t	num;
	bool	is_negative;

	is_negative = false;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			is_negative = true;
	}
	if (*str == '\0')
		return (false);
	num = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == false)
			return (false);
		if (is_negative == false && num > INT_MAX)
			return (false);
		else if (is_negative == true && -1 * num < INT_MIN)
			return (false);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (true);
}
