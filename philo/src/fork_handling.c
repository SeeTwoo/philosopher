/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <seetwoo@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:36:19 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/29 22:37:57 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	pick_forks(t_philo *philo, int *fork_states, int id, int nb_ph)
{
	fork_states[id] = TAKEN;
	phlog(philo, FORK);
	fork_states[(id + 1) % nb_ph] = TAKEN;
	phlog(philo, FORK);
}

int	try_to_pick(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	int	*fork_states;
	int	id;
	int	nb_ph;

	fork_states = philo->sim->fork_states;
	id = philo->id;
	nb_ph = philo->nb_ph;
	pthread_mutex_lock(first);
	pthread_mutex_lock(second);
	if (fork_states[id] == FREE && fork_states[(id + 1) % nb_ph] == FREE)
	{
		pick_forks(philo, fork_states, id, nb_ph);
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
		return (SUCCESS);
	}
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
	return (FAILURE);
}

void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 == 0)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	while (try_to_pick(philo, first, second) == FAILURE)
	{
		pthread_mutex_lock(&philo->sim->death_mutex);
		if (philo->sim->someone_died || philo->sim->all_ate)
		{
			pthread_mutex_unlock(&philo->sim->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->sim->death_mutex);
		usleep(100);
	}
}

void	put_down_fork(t_philo *philo, int *fork_states, int id, int nb_ph)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	fork_states[id] = FREE;
	fork_states[(id + 1) % nb_ph] = FREE;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
