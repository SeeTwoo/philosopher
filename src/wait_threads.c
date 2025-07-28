/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:07:59 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 12:19:38 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	wait_threads(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_ph)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
}
