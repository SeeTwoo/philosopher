/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:03:01 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/29 20:33:58 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//this needs better freees
void	init_mutexes(t_sim *sim)
{
	int	i;

	pthread_mutex_init(&sim->death_mutex, NULL);
	pthread_mutex_init(&sim->write_mutex, NULL);
	i = 0;
	while (i < sim->nb_ph)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		pthread_mutex_init(&sim->philos[i].meal_mutex, NULL);
		i++;
	}
}

int	init_philosophers(t_sim *sim)
{
	int		i;

	i = 0;
	while (i < sim->nb_ph)
	{
		sim->philos[i].min_think = sim->min_think;
		sim->philos[i].nb_ph = sim->nb_ph;
		sim->philos[i].id = i;
		sim->philos[i].meal_count = 0;
		sim->philos[i].left_fork = &(sim->forks[i]);
		sim->philos[i].right_fork = &(sim->forks[(i + 1) % sim->nb_ph]);
		sim->philos[i].sim = sim;
		sim->fork_states[i] = 0;
		i++;
	}
	init_mutexes(sim);
	return (0);
}
