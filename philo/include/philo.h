/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:22:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/20 21:51:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>
# include <inttypes.h>

# include "types.h"
# include "utils.h"
# include "error.h"
# include "argument_parsing.h"
# include "cleanup.h"
# include "dining_philosophers_simulation.h"
# include "initialization.h"

# ifndef WRITE_BLOCK_SIZE
#  define WRITE_BLOCK_SIZE 16384
# endif

# ifndef NO_EAT_LIMIT
#  define NO_EAT_LIMIT -1
# endif

#endif
