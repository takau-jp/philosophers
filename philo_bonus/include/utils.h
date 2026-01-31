/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:35:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 18:27:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

unsigned long	ft_abs_ulong(long n);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isspace(int c);
int				ft_isdigit(int c);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *dest, const char *src);
size_t			ft_strlen(const char *s);

#endif