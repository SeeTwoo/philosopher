/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:22:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 15:08:13 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCS_H
# define PHILO_FUNCS_H

int			check_usage(int ac, char **av);
long		get_time_ms(void);
void		init_mutexes(t_sim *sim);
int			init_philosophers(t_sim *sim);
void		monitor_threads(t_sim *sim);
void		parsing(char **av, t_sim *args);
void		*philo_runtime(void *philo);
int			phlog(t_philo *philo, char *s);
void		start_threads(t_sim *sim);
void		wait_threads(t_sim *sim);

#endif
