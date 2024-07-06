/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:09:18 by tialbert          #+#    #+#             */
/*   Updated: 2024/07/06 10:41:06 by tialbert         ###   ########.fr       */
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
	if (ft_strncmp(state, "eat", 3) == 0)
	{
		printf("%lld - %d is eating\n",
			(*philo_lst)->t_after_eat, (*philo_lst)->seat);
		usleep((*philo_lst)->philo_const->t_eat * 1000);
	}
	else if (ft_strncmp(state, "sleep", 5) == 0)
	{
		printf("%lld - %d is sleeping\n",
			(*philo_lst)->t_after_eat, (*philo_lst)->seat);
		usleep((*philo_lst)->philo_const->t_sleep * 1000);
	}
}
