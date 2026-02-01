/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:22:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/01 19:15:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <sys/time.h>
# include <inttypes.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>
# include <pthread.h>

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

# define NO_EAT_LIMIT -1

#endif
