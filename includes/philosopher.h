/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:11:52 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/18 22:33:16 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TOO_MUCH_ARG "too much arguments\n"
# define NOT_ENOUGH_ARG "not enough arguments\n"
# define ARG_NUMBER "invalid argument number.\n"
# define INVALID_ARG "invalid argument. Arguments can only contain digits\n"

typedef struct s_sim	t_sim;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

struct s_sim
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	long			start_time;
	int				someone_died;
	int				max_meal_reached;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	write_mutex;
	t_philo			*philos;
	pthread_mutex_t	*forks;
};

struct s_philo
{
	int				id;
	int				meal_count;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_sim			*sim;
};

int		check_usage(int ac, char **av);
t_philo	*init_philosophers(t_phvar *args);
void	parsing(char **av, t_phvar *args);
void	*philo_runtime(void *philo);
void	start_threads(t_philo *philos);
void	wait_threads(t_philo *philos);

#endif
