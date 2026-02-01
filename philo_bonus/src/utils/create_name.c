/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 00:53:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/02 00:53:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	itoa_buf(int n, char *buf);
static int	count_digit(int n);

void	create_name(char *buf, char *prefix, int index)
{
	ft_strcpy(buf, prefix);
	itoa_buf(index, buf + ft_strlen(buf));
}

void	itoa_buf(int n, char *buf)
{
	unsigned int	un;
	int				digit;

	digit = count_digit(n);
	buf[digit] = '\0';
	un = n;
	if (n < 0)
		un = -n;
	while (digit--)
	{
		buf[digit] = (un % 10) + '0';
		if (n < 0 && digit == 1)
		{
			buf[0] = '-';
			break ;
		}
		un /= 10;
	}
}

static int	count_digit(int n)
{
	int	digit;

	if (!n)
		return (1);
	digit = 0;
	if (n < 0)
		digit = 1;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
