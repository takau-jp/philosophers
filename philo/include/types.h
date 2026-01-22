/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:46:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/22 16:05:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

// struct
typedef struct s_simulation		t_simulation;
typedef struct s_timestamp		t_timestamp;
typedef struct s_philo			t_philo;

// enum
typedef enum e_state		t_state;

enum e_state
{
	STATE_READY,
	STATE_GOING,
	STATE_END,
	STATE_DEAD,
	STATE_ERROR,
};

struct s_simulation
{
	int				n_philos;
	int64_t			time_to_die;
	int64_t			time_to_eat;
	int64_t			time_to_sleep;
	int				must_eat_counts;
	struct timeval	start;
	pthread_mutex_t	state_mutex;
	t_state			state;
};

struct s_timestamp
{
	struct timeval	timeval;
	int64_t			timestamp;
};

struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	t_simulation	*simulation;
	t_timestamp		last_meal;
	int64_t			eat_count;
	bool			is_error;
};

#endif