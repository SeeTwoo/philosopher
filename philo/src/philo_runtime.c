/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:56:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/29 19:24:43 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_sleep(long duration, t_sim *sim)
{
	long			start_sleep;
	pthread_mutex_t	*state_mutex;

	start_sleep = get_time_ms();
	pthread_mutex_lock(&sim->death_mutex);
	state_mutex = &sim->death_mutex;
	pthread_mutex_unlock(&sim->death_mutex);
	while (get_time_ms() - start_sleep < duration)
	{
		pthread_mutex_lock(state_mutex);
		if (sim->someone_died || sim->all_ate)
		{
			pthread_mutex_unlock(state_mutex);
			return (SOMEONE_DIED);
		}
		pthread_mutex_unlock(state_mutex);
		usleep(200);
	}
	return (ALL_RIGHT);
}

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

void	philo_eat(t_philo *philo)
{
	int	*fork_states;
	int	id;
	int	nb_ph;

	fork_states = philo->sim->fork_states;
	id = philo->id;
	nb_ph = philo->nb_ph;
	pick_up_fork(philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time_ms();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	phlog(philo, EAT);
	ft_sleep(philo->sim->tte, philo->sim);
	put_down_fork(philo, fork_states, id, nb_ph);
}

void	*philo_runtime(void *philo)
{
	t_philo	*ph;
	t_sim	*sim;

	ph = (t_philo *)philo;
	sim = ph->sim;
	wait_for_start(ph);
	delay(ph);
	while (1)
	{
		philo_eat(ph);
		phlog(ph, SLEEP);
		if (ft_sleep(sim->tts, sim))
			break ;
		phlog(ph, THINK);
		if (ft_sleep(ph->min_think, sim))
			break ;
	}
	return (NULL);
}
