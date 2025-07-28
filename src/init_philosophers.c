/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:03:01 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 12:32:06 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//this needs better freees

int	init_philosophers(t_sim *sim)
{
	int		i;
	long	start_time;

	sim->philos = malloc(sizeof(t_philo) * sim->nb_ph);
	if (!(sim->philos))
		return (1);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->nb_ph);
	if (!(sim->forks))
		return (1);
	i = 0;
	start_time = get_time_ms();
	while (i < sim->nb_ph)
	{
		sim->philos[i].id = i;
		sim->philos[i].meal_count = 0;
		sim->philos[i].nb_ph = sim->nb_ph;
		sim->philos[i].last_meal_time = sim->start_time;
		i++;
	}
	return (0);
}
