/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:42:36 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 22:01:25 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	delay(t_philo *philo)
{
	if (philo->sim->nb_ph % 2 == 1)
	{
		phlog(philo, THINK);
		ft_sleep(((philo->sim->tte / (philo->sim->nb_ph - 1)) * (philo->id)), philo->sim);
	}
}
