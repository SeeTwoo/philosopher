/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:21:07 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/29 17:57:56 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

typedef struct s_sim	t_sim;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

struct s_philo
{
	int				id;
	int				nb_ph;
	int				meal_count;
	long			start_time;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	t_sim			*sim;
};

struct s_sim
{
	int				nb_ph;
	int				ttd;
	int				tte;
	int				tts;
	int				max_meal;
	long			start_time;
	int				someone_died;
	int				all_ate;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	write_mutex;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];
	int				fork_states[200];
};

//ttd = time to die
//tte = time to eat
//tts = time to sleep

#endif
