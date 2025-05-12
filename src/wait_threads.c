/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:07:59 by wbeschon          #+#    #+#             */
/*   Updated: 2025/05/12 13:09:54 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	wait_threads(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
}
