/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:11:00 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/18 22:20:23 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_sim	sim;
	
	if (!check_usage(ac, av))
		return (1);
	parsing(av, &sim);
	if (args.philo_number == 0)
		return (0);
	init_philos(&args);
	start_threads(sim.philos);
	wait_threads(sim.philos);
	return (0);
}
