/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:46:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/16 17:31:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_ctx	t_ctx;
typedef struct s_philo	t_philo;

struct s_philo
{
	int				index;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	int64_t			eat_count;
};

struct s_ctx
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_counts;
	t_philo			*philos;
	void			**pthread_retvals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	monitor_mutex;
	pthread_mutex_t	print_mutex;
	struct timeval	start_time;
};

#endif