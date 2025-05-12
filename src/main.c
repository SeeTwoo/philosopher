/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:11:00 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/11 22:40:11 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_phvar	args;

	if (!check_usage(ac, av))
		return (1);
	parsing(av, &args);
	args->thread = malloc(sizeof(p_threa
	return (0);
}
