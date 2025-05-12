/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:11:52 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/12 13:32:18 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define TOO_MUCH_ARG "too much arguments\n"
# define NOT_ENOUGH_ARG "not enough arguments\n"
# define ARG_NUMBER "invalid argument number.\n"
# define INVALID_ARG "invalid argument. Arguments can only contain digits\n"

typedef struct s_phvar	t_phvar;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

struct s_phvar
{
	int			philo_number;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			max_meal;
};

struct s_philo
{
	pthread_t	thread;
	t_phvar		*args;
	int			index;
	int			dead;
	int			fork_state;
};

enum e_fork_state
{
	TAKEN,
	FREE
};

int		check_usage(int ac, char **av);
t_philo	**init_philosophers(t_phvar *args);
void	parsing(char **av, t_phvar *args);
void	*philo_runtime(void *philo);
void	start_threads(t_philo **philos);
void	wait_threads(t_philo **philos);

#endif
