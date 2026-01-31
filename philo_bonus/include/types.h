/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:46:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/31 22:12:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

// struct
typedef struct s_simulation		t_simulation;
typedef struct s_timestamp		t_timestamp;
typedef struct s_philo			t_philo;
typedef struct s_philo_pid		t_philo_pid;

struct s_simulation
{
	int				number_of_philos;
	int64_t			time_to_die;
	int64_t			time_to_eat;
	int64_t			time_to_sleep;
	int				must_eat_counts;
	struct timeval	start;
	sem_t			*fork_sem;
	sem_t			*log_sem;
	sem_t			*eat_count_sem;
};

struct s_timestamp
{
	struct timeval	timeval;
	int64_t			timestamp;
};

struct s_philo
{
	int			id;
	sem_t		*access_sem;
	sem_t		*used_sem;
	sem_t		*meal_time_sem;
	t_timestamp	last_meal;
	int64_t		eat_count;
};

struct s_philo_pid
{
	int		id;
	pid_t	pid;
};

enum e_exit_state
{
	EXIT
}

#endif