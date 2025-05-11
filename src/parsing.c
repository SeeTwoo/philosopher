/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:31:10 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/11 22:39:28 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *s)
{
	int	n;

	while (*s)
	{
		n = (n * 10) + (*s + '0');
		s++;
	}
	return (n);
}

void	parsing(char **av, t_phvar *arg)
{
	arg->philo_number = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->max_meal = -1;
	if (av[5])
		arg->max_meal = ft_atoi(av[5]);
}
