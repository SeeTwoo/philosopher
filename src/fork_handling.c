/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:56:06 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 12:37:11 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//instantaneous - ish
void	pick_up_fork(t_philo *philo)
{
	int	i;

	i = philo->id;
	printf("i = %d\n", (i + 1) % philo->nb_ph);
	if (i % 2)
	{
		pthread_mutex_lock(&philo->sim->forks[i]);
		pthread_mutex_lock(&philo->sim->forks[(i + 1) % philo->nb_ph]);
	}
	else
	{
		pthread_mutex_lock(&philo->sim->forks[(i + 1) % philo->nb_ph]);
		pthread_mutex_lock(&philo->sim->forks[i]);
	}
}

//instantaneous - ish
void	put_down_fork(t_philo *philo)
{
	int	i;
	int	nb_ph;

	i = philo->id;
	nb_ph = philo->sim->nb_ph;
	if (i % 2)
	{
		pthread_mutex_unlock(&philo->sim->forks[i]);
		pthread_mutex_unlock(&philo->sim->forks[(i + 1) % philo->nb_ph]);
	}
	else
	{
		pthread_mutex_unlock(&philo->sim->forks[(i + 1) % philo->nb_ph]);
		pthread_mutex_unlock(&philo->sim->forks[i]);
	}
}
