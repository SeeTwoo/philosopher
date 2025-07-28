/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:56:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 17:08:35 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	pick_up_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
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
	long	start_sleep;

	start_sleep = get_time_ms();
	while (get_time_ms() - start_sleep < duration)
	{
		pthread_mutex_lock(&sim->death_mutex);
		if (sim->someone_died)
		{
			pthread_mutex_unlock(&sim->death_mutex);
			return (SOMEONE_DIED);
		}
		pthread_mutex_unlock(&sim->death_mutex);
		usleep(500);
	}
	return (ALL_RIGHT);
}

int	philo_eat(t_philo *philo)
{
	int	return_state;

	pick_up_fork(philo);
	phlog(philo, FORK);
	phlog(philo, FORK);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->meal_mutex);
	phlog(philo, EAT);
	return_state = ft_sleep(philo->sim->tte, philo->sim);
	put_down_fork(philo);
	return (return_state);
}

void	*philo_runtime(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		if (philo_eat(ph) == SOMEONE_DIED)
			return (NULL);
		phlog(ph, SLEEP);
		if (ft_sleep(ph->sim->tts, ph->sim) == SOMEONE_DIED)
			return (NULL);
		phlog(ph, THINK);
	}
	return (NULL);
}
