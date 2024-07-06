/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:42:52 by tialbert          #+#    #+#             */
/*   Updated: 2024/07/06 10:41:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo_const {
	long long	philos_num;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	long long	eat_num;
	int			queue;
}				t_philo_const;

typedef struct s_cond {
	pthread_mutex_t	death_mutex;
	int				death;
	int				start;
}				t_cond;

typedef struct s_philo_lst {
	int					seat;
	int					kill;
	int					eating;
	t_philo_const		*philo_const;
	long long			t_init;
	long long			t_after_eat;
	pthread_mutex_t		mutex;
	struct s_philo_lst	*next;
	struct s_philo_lst	*prev;
	t_cond				*philo_cond;
}					t_philo_lst;

int			get_args(t_philo_const *philo, char **argv, int argc);
void		argument_error(int type);
t_philo_lst	*create_lst(t_philo_const *philo);
void		*run_thread(void *arg);
void		*watcher(void *arg);
int			start_mutex(t_philo_lst **philo_lst);
int			end_lst(t_philo_lst *philo_lst);
int			get_init_time(t_philo_lst **philo_lst);
long long	get_time(t_philo_lst *philo_lst);
int			get_eat_time(t_philo_lst *philo_lst);
int			starve_check(t_philo_lst *philo_lst);
void		write_state(t_philo_lst **philo_lst, char *state);

#endif
