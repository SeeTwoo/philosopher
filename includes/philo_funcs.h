/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:22:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/07/28 12:18:09 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCS_H
# define PHILO_FUNCS_H

int			check_usage(int ac, char **av);
long		get_time_ms(void);
int			init_philosophers(t_sim *sim);
void		monitor_threads(t_sim *sim);
void		parsing(char **av, t_sim *args);
void		*philo_runtime(void *philo);
int			phlog(t_philo *philo, char *s);
void		pick_up_fork(t_philo *philo);
void		put_down_fork(t_philo *philo);
void		start_threads(t_sim *sim);
void		wait_threads(t_sim *sim);

#endif
