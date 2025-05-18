/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:03:01 by wbeschon          #+#    #+#             */
/*   Updated: 2025/05/19 00:09:52 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//this needs better freees

long	get_ts(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec);
}

int	init_philosophers(t_sim *sim)
{
	int		i;
	long	start_time;

	sim->philos = malloc(sizeof(t_philo) * sim->nb_philos);
	if (!(sim->philos))
		return (1);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->nb_philos);
	if (!(sim->forks))
		return (1);
	i = 0;
	start_time = gettimeofday
	while (i < sim->nb_philos)
	{
		sim->philos[i]->meal_count = 0;
		sim->philos[i]->last_meal_time = get
	}
	return (0);
}
