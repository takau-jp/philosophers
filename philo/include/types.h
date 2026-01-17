/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:46:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 23:28:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

// struct
typedef struct s_settings	t_settings;
typedef struct s_simulation	t_simulation;
typedef struct s_ctx		t_ctx;
typedef struct s_philo		t_philo;
// enum
typedef enum e_state		t_state;

struct s_settings
{
	int	n_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_counts;
};

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
	struct timeval	start_time;
	pthread_mutex_t	state_mutex;
	t_state			state;
	pthread_mutex_t	count_mutex;
	int				finished_philos_count;
	pthread_mutex_t	print_mutex;
};

struct s_philo
{
	int				index;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	int64_t			eat_count;
	t_settings		*settings;
	t_simulation	*simulation;
};

struct s_ctx
{
	t_philo			*philos;
	void			**pthread_retvals;
	pthread_mutex_t	*forks;
};

#endif