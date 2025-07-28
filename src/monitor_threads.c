/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:57:16 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 16:42:31 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	monitor_threads(t_sim *sim)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = sim->philos;
	while (1)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (get_time_ms() - philos[i].last_meal_time > sim->ttd)
		{
			pthread_mutex_lock(&sim->death_mutex);
			sim->someone_died = 1;
			pthread_mutex_unlock(&sim->death_mutex);
			pthread_mutex_lock(&sim->write_mutex);
			printf("%ld philo number %d %s\n", get_time_ms() - sim->start_time, i, DIED);
			break ;
		}
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
		if (i == sim->nb_ph)
			i = 0;
	}
}
