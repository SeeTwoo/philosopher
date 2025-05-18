/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:59:39 by wbeschon          #+#    #+#             */
/*   Updated: 2025/05/18 19:00:17 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	start_threads(t_philo *philo)
{
	int	i;
	int	lim;

	i = 0;
	lim = philo->args->philo_number;
	while (1)
	{
		pthread_create(&(philo->thread), NULL, philo_runtime, (void *)philo);
		if (i == lim - 1)
			break ;
		philo = philo->neighbour;
		i++;
	}
}
