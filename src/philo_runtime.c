/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:56:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 12:54:05 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//lasts some time
int	philo_eat(t_philo *philo)
{
	int		i;
	long	start_meal;

	i = philo->id;
	pick_up_fork(philo);
	start_meal = get_time_ms();
	philo->last_meal_time = start_meal;
	while (get_time_ms() - start_meal < philo->sim->tte)
	{
		pthread_mutex_lock(&philo->sim->death_mutex);
		if (philo->sim->someone_died)
		{
			pthread_mutex_unlock(&philo->sim->death_mutex);
			return (SOMEONE_DIED);
		}
		pthread_mutex_unlock(&philo->sim->death_mutex);
		usleep(10);
	}
	put_down_fork(philo);
	return (ALL_RIGHT);
}

//lasts some time
int	philo_sleep(t_philo *philo)
{
	long	start_sleep;

	start_sleep = get_time_ms();
	phlog(philo, SLEEP);
	while (get_time_ms() - start_sleep < philo->sim->tts)
	{
		pthread_mutex_lock(&philo->sim->death_mutex);
		if (philo->sim->someone_died)
		{
			pthread_mutex_unlock(&philo->sim->death_mutex);
			return (SOMEONE_DIED);
		}
		pthread_mutex_unlock(&philo->sim->death_mutex);
		usleep(10);
	}
	return (ALL_RIGHT);
}

void	*philo_runtime(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id == 1)
		usleep(10);
	printf("hello from thread number %d\n", ph->id);
	fflush(stdout);
	while (1)
	{
		if (philo_eat(ph) == 1)
			return (NULL);
		if (philo_sleep(ph) == 1)
			return (NULL);
		phlog(ph, THINK);
	}
	return (NULL);
}
