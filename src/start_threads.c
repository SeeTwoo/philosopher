/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:59:39 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 12:19:16 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	start_threads(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_ph)
	{
		pthread_create(&(sim->philos[i].thread), NULL,
			philo_runtime, &(sim->philos[i]));
		i++;
	}
}
