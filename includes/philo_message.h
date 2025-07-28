/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:12:38 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 16:34:28 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MESSAGE_H
# define PHILO_MESSAGE_H

# define FORK "has taken a fork"
# define EAT "\e[31mis eating\e[0m"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

# define TOO_MUCH_ARG "too much arguments\n"
# define NOT_ENOUGH_ARG "not enough arguments\n"
# define ARG_NUMBER "invalid argument number.\n"
# define INVALID_ARG "invalid argument. Arguments can only contain digits\n"

# define I_AM_DEAD 2
# define SOMEONE_DIED 1
# define ALL_RIGHT 0

#endif
