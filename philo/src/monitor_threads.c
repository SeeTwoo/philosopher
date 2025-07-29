/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:57:16 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 19:45:43 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//pthread_mutex_lock(&sim->death_mutex);
//pthread_mutex_unlock(&sim->death_mutex);
int	check_death(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_ph)
	{
		pthread_mutex_lock(&sim->philos[i].meal_mutex);
		if (get_time_ms() - sim->philos[i].last_meal_time > sim->ttd)
		{
			pthread_mutex_unlock(&sim->philos[i].meal_mutex);
			pthread_mutex_lock(&sim->death_mutex);
			if (!sim->someone_died && !sim->all_ate)
			{
				sim->someone_died = 1;
				pthread_mutex_lock(&sim->write_mutex);
				printf("%ld %d %s\n", get_time_ms() - sim->start_time,
					sim->philos[i].id + 1, DIED);
				pthread_mutex_unlock(&sim->write_mutex);
			}
			pthread_mutex_unlock(&sim->death_mutex);
			return (1);
		}
		pthread_mutex_unlock(&sim->philos[i].meal_mutex);
		i++;
	}
	return (0);
}

int	all_ate(t_sim *sim)
{
	int	i;
	int	finished_philos;

	if (sim->max_meal == -1)
		return (0);
	finished_philos = 0;
	i = 0;
	while (i < sim->nb_ph)
	{
		pthread_mutex_lock(&sim->philos[i].meal_mutex);
		if (sim->philos[i].meal_count >= sim->max_meal)
			finished_philos++;
		pthread_mutex_unlock(&sim->philos[i].meal_mutex);
		i++;
	}
	if (finished_philos == sim->nb_ph)
	{
		pthread_mutex_lock(&sim->death_mutex);
		sim->all_ate = 1;
		pthread_mutex_unlock(&sim->death_mutex);
		return (1);
	}
	return (0);
}

void	monitor_simulation(t_sim *sim)
{
	if (sim->nb_ph == 0)
		return ;
	while (1)
	{
		if (check_death(sim) || all_ate(sim))
			break ;
		usleep(100);
	}
}
