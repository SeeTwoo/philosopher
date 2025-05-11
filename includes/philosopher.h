/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seetwoo <waltibee@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:11:52 by seetwoo           #+#    #+#             */
/*   Updated: 2025/05/11 22:39:44 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>

# define TOO_MUCH_ARG "too much arguments\n"
# define NOT_ENOUGH_ARG "not enough arguments\n"
# define ARG_NUMBER "invalid argument number.\n"
# define INVALID_ARG "invalid argument. Arguments can only contain digits\n"

typedef struct s_phvar	t_phvar;

struct s_phvar
{
	int	philo_number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meal;
};

int		check_usage(int ac, char **av);
void	parsing(char **av, t_phvar *args);

#endif
