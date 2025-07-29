/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lone_philo_runtime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:13:05 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 18:15:09 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*lone_philo_runtime(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	phlog(philo, FORK);
	ft_sleep(philo->sim->ttd, philo->sim);
	return (NULL);
}
