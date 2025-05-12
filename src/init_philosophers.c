/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:03:01 by wbeschon          #+#    #+#             */
/*   Updated: 2025/05/12 13:15:18 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	**init_philosophers(t_phvar *args)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * (args->philo_number + 1));
	if (!philos)
		return (NULL);
	philos[args->philo_number] = NULL;
	i = 0;
	while (philos[i])
	{
		philos[i] = malloc(sizeof(t_philo *));
		if (!(philos[i]))
			return (NULL);									//better later
		philos[i]->args = args;
		philos[i]->index = i;
		philos[i]->dead = 0;
		philos[i]->fork_state = FREE;
		i++;
	}
	return (philos);
}
