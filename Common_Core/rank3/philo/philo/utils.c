/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:27:25 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/16 21:15:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

static int	check_nb(char const *str)
{
	while (*str != 0)
	{
		if (*str < '0' || *(str++) > '9')
			return (1);
	}
	return (0);
}

static long long	ft_atoi(char const *str)
{
	unsigned int	nb;

	if (check_nb(str) == 1)
		return (-1);
	nb = 0;
	while (*str != 0)
		nb = nb * 10 + (*(str++) - 48);
	return (nb);
}

int	get_args(t_philo_const *philo, char **argv, int argc)
{
	philo->philos_num = ft_atoi(argv[1]);
	if (philo->philos_num == -1 || philo->philos_num == 0)
		return (1);
	philo->t_die = ft_atoi(argv[2]);
	if (philo->t_die == -1)
		return (1);
	philo->t_eat = ft_atoi(argv[3]);
	if (philo->t_eat == -1)
		return (1);
	philo->t_sleep = ft_atoi(argv[4]);
	if (philo->t_sleep == -1)
		return (1);
	if (argc == 6)
	{
		philo->eat_num = ft_atoi(argv[5]);
		if (philo->eat_num == -1)
			return (1);
	}
	else
		philo->eat_num = -1;
	return (0);
}

void	start_mutex(t_philo_lst *philo_lst)
{
	while (philo_lst->seat <= philo_lst->philo_const->philos_num)
	{
		pthread_mutex_init(&philo_lst->mutex, NULL);
		philo_lst = philo_lst->next;
	}
}

void	end_lst(t_philo_lst *philo_lst)
{
	t_philo_lst	*lst_next;
	int			i;
	int			philos_num;

	i = 0;
	philos_num = philo_lst->philo_const->philos_num;
	while (philo_lst->seat <= philo_lst->philo_const->philos_num)
	{
		pthread_mutex_destroy(&philo_lst->mutex);
		philo_lst = philo_lst->next;
	}
	while (i < philos_num)
	{
		lst_next = philo_lst->next;
		free(philo_lst);
		philo_lst = lst_next;
		i++;
	}
}
