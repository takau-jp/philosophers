/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:09:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/15 23:09:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;

	mem = (unsigned char *)s;
	c = (unsigned char)c;
	while (n--)
	{
		*mem = c;
		mem++;
	}
	return (s);
}
