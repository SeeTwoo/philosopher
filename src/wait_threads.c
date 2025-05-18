/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:07:59 by wbeschon          #+#    #+#             */
/*   Updated: 2025/05/18 18:15:00 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	wait_threads(t_philo *philo)
{
	int	i;
	int	philo_number;

	i = 0;
	philo_number = philo->args->philo_number;
	while (1)
	{
		pthread_join(philo->thread, NULL);
		if (i < philo_number - 1)
			break ;
		philo = philo->neighbour;
		i++;
	}
}
