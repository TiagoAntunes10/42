/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:42:52 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/16 18:07:28 by tialbert         ###   ########.fr       */
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
}				t_philo_const;

typedef struct s_philo_lst {
	int					seat;
	pthread_mutex_t		mutex;
	t_philo_const		*philo_const;
	struct s_philo_lst	*next;
	struct s_philo_lst	*prev;
}					t_philo_lst;

int			get_args(t_philo_const *philo, char **argv, int argc);
void		argument_error(int type);
void		start_philo(t_philo_const *philo);
t_philo_lst	*create_lst(t_philo_const *philo);
void		start_mutex(t_philo_lst *philo_lst);
void		end_lst(t_philo_lst *philo_lst);

#endif
