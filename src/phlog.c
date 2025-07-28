/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlog.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:30:23 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 16:28:43 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	phlog(t_philo *philo, char *s)
{
	pthread_mutex_lock(&(philo->sim->death_mutex));
	if (philo->sim->someone_died)
	{
		pthread_mutex_unlock(&(philo->sim->death_mutex));
		return (SOMEONE_DIED);
	}
	pthread_mutex_unlock(&(philo->sim->death_mutex));
	pthread_mutex_lock(&(philo->sim->write_mutex));
	printf("%ld philo number %d %s\n", get_time_ms() - philo->start_time, philo->id, s);
	pthread_mutex_unlock(&(philo->sim->write_mutex));
	return (ALL_RIGHT);
}
