/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:56:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/05/18 18:52:05 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_runtime(void *philo)
{
	t_philo	*myself;

	myself = (t_philo *)philo;
	printf("hey, this is philo number %d. My neighbour is number %d\n",
			myself->index, myself->neighbour->index);
	return (NULL);
}
