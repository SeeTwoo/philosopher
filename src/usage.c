/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:27:12 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/12 00:37:21 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	just_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_usage(int ac, char **av)
{
	if (ac < 5)
	{
		printf("%s", NOT_ENOUGH_ARG);
		return (0);
	}
	if (ac > 6)
	{
		printf("%s", TOO_MUCH_ARG);
		return (0);
	}
	if (!just_digit(av))
	{
		printf("%s", INVALID_ARG);
		return (0);
	}
	return (1);
}
