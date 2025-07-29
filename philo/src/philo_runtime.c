/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:56:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/29 22:37:00 by seetwoo          ###   ########.fr       */
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
