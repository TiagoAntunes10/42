/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:09:18 by tialbert          #+#    #+#             */
/*   Updated: 2024/07/18 14:42:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

static int	ft_strncmp(const char *s1, const char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	write_state(t_philo_lst **philo_lst, char *state)
{
	pthread_mutex_lock(&(*philo_lst)->philo_cond->time_mutex);
	if (ft_strncmp(state, "eat", 3) == 0)
	{
		printf("%lld - %d is eating\n",
			(*philo_lst)->t_after_eat, (*philo_lst)->seat);
		pthread_mutex_unlock(&(*philo_lst)->philo_cond->time_mutex);
		usleep((*philo_lst)->philo_const->t_eat * 1000);
	}
	else if (ft_strncmp(state, "sleep", 5) == 0)
	{
		printf("%lld - %d is sleeping\n",
			(*philo_lst)->t_now, (*philo_lst)->seat);
		pthread_mutex_unlock(&(*philo_lst)->philo_cond->time_mutex);
		usleep((*philo_lst)->philo_const->t_sleep * 1000);
	}
	else if (ft_strncmp(state, "fork", 4) == 0)
	{
		printf("%lld - %d has taken a fork\n",
			(*philo_lst)->t_now, (*philo_lst)->seat);
		pthread_mutex_unlock(&(*philo_lst)->philo_cond->time_mutex);
	}
}

int	start_sim(t_philo_lst *philo_lst)
{
	long long		eat_limit;

	eat_limit = philo_lst->philo_const->eat_num;
	if (get_current_time(philo_lst, 0) == -1)
		return (-1);
	while (eat_limit-- >= 0 || eat_limit < 0)
	{
		if (philo_sim(philo_lst) == -1)
			return (0);
		if (eat_limit == 0)
		{
			pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
			philo_lst->philo_cond->death = -1;
			pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
			return (-1);
		}
	}
	return (0);
}
