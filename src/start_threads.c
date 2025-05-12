/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:59:39 by wbeschon          #+#    #+#             */
/*   Updated: 2025/05/12 13:31:52 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	start_threads(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		pthread_create(&(philos[i]->thread), NULL, philo_runtime, (void *)philos[i]);
		i++;
	}
}
