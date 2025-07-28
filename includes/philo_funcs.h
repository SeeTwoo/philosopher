/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:22:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 18:54:21 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCS_H
# define PHILO_FUNCS_H

int			check_usage(int ac, char **av);
void		destroy_all(t_sim *sim);
int			ft_sleep(long duration, t_sim *sim);
long		get_time_ms(void);
void		init_mutexes(t_sim *sim);
int			init_philosophers(t_sim *sim);
void		*lone_philo_runtime(void *arg);
void		monitor_simulation(t_sim *sim);
void		parsing(char **av, t_sim *args);
void		*philo_runtime(void *philo);
void		phlog(t_philo *philo, char *s);
int			start_threads(t_sim *sim);
void		wait_threads(t_sim *sim);

#endif
