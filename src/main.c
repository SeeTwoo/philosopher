/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:11:00 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/12 13:11:02 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*hello_void(void *arg)
{
	printf("%s", (char *)arg);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_phvar		args;
	t_philo		**philos;

	if (!check_usage(ac, av))
		return (1);
	parsing(av, &args);
	if (args.philo_number == 0)
		return (0);
	philos = init_philosophers(&args);
	start_threads(philos);
	wait_threads(philos);
	return (0);
}
