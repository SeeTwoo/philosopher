/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:31:10 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/29 18:00:50 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	return (n);
}

int	parsing(char **av, t_sim *sim)
{
	sim->nb_ph = ft_atoi(av[1]);
	if (sim->nb_ph > 200)
	{
		printf("%s", TOO_MUCH_PHILO);
		return (1);
	}
	sim->ttd = ft_atoi(av[2]);
	sim->tte = ft_atoi(av[3]);
	sim->tts = ft_atoi(av[4]);
	if (av[5])
		sim->max_meal = ft_atoi(av[5]);
	else
		sim->max_meal = -1;
	sim->someone_died = 0;
	sim->all_ate = 0;
	return (0);
}
