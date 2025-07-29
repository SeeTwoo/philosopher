/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:59:39 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 19:19:20 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_start_time(t_sim *sim)
{
	long	total_wait;

	total_wait = sim->nb_ph * 2;
	return (get_time_ms() + total_wait);
}

int	start_threads(t_sim *sim)
{
	int	i;

	i = 0;
	sim->start_time = get_start_time(sim);
	if (sim->nb_ph == 1)
	{
		sim->philos[0].last_meal_time = sim->start_time;
		if (pthread_create(&sim->philos[i].thread, NULL,
				&lone_philo_runtime, &sim->philos[i]))
			return (1);
		return (0);
	}
	while (i < sim->nb_ph)
	{
		sim->philos[i].last_meal_time = sim->start_time;
		if (pthread_create(&(sim->philos[i].thread), NULL,
				philo_runtime, &(sim->philos[i])))
			return (1);
		i++;
	}
	return (0);
}
