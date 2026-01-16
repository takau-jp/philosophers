/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:59:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/15 23:04:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGUMENTS_H
# define PARSE_ARGUMENTS_H

bool	parse_arguments(t_ctx *ctx, int argc, char *argv[]);
bool	is_int(char *str);

#endif
