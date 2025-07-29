/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:11:00 by seetwoo           #+#    #+#             */
/*   Updated: 2025/07/28 21:11:07 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	main(int ac, char **av)
{
	t_sim	sim;

	if (!check_usage(ac, av))
		return (1);
	parsing(av, &sim);
	if (sim.nb_ph == 0)
		return (0);
	if (init_philosophers(&sim))
		return (printf("%s\n", FAILED_MALLOC), 1);
	if (start_threads(&sim))
		return (1);
	monitor_simulation(&sim);
	wait_threads(&sim);
	destroy_all(&sim);
	return (0);
}
