/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:42:52 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/10 11:03:15 by tialbert         ###   ########.fr       */
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

typedef struct s_philo {
	int				philos_num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				eat_num;
	int				i;
	pthread_mutex_t	*mutex;
}				t_philo;

int		get_args(t_philo *philo, char **argv, int argc);
void	argument_error(int type);
void	start_philo(t_philo *philo);

#endif
