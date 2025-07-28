/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:56:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 22:26:02 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	pick_up_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		phlog(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		phlog(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		phlog(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		phlog(philo, FORK);
	}
}

void	put_down_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

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
	pick_up_fork(philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time_ms();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	phlog(philo, EAT);
	ft_sleep(philo->sim->tte, philo->sim);
	put_down_fork(philo);
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
		pthread_mutex_lock(&sim->death_mutex);
		if (sim->someone_died || sim->all_ate)
		{
			pthread_mutex_unlock(&sim->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&sim->death_mutex);
		philo_eat(ph);
		phlog(ph, SLEEP);
		if (ft_sleep(ph->sim->tts, ph->sim))
			break ;
		phlog(ph, THINK);
	}
	return (NULL);
}
