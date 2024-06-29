/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:51:49 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/29 11:21:06 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

int	get_init_time(t_philo_lst *philo_lst)
{
	struct timeval	t_init;
	int				i;

	if (gettimeofday(&t_init, NULL) != 0)
		return (-1);
	i = 0;
	while (i++ < philo_lst->philo_const->philos_num)
	{
		philo_lst->t_init = t_init.tv_sec * 1000 + t_init.tv_usec / 1000;
		philo_lst = philo_lst->next;
	}
	return (0);
}

long	get_time(t_philo_lst *philo_lst)
{
	struct timeval	t_now;
	
	if (gettimeofday(&t_now, NULL) != 0)
		return (-1);
	return ((t_now.tv_sec * 1000 + t_now.tv_usec / 1000) - philo_lst->t_init);
}

long	starve_check(t_philo_lst *philo_lst)
{
	struct timeval	t_now;
	
	if (gettimeofday(&t_now, NULL) != 0)
		return (-1);
	if ((t_now.tv_sec * 1000 + t_now.tv_usec / 1000) - philo_lst->t_after_eat >= philo_lst->philo_const->t_die)
		return (1);
	return (0);
}
