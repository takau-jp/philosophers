/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:45:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 15:38:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_PARSING_H
# define ARGUMENT_PARSING_H

bool	parse_arguments(int argc, char *argv[], t_simulation *simulation);
bool	is_int(char *str);

#endif
