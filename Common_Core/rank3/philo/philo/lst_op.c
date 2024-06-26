/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:46:20 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/29 11:08:15 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

static t_philo_lst	*start_lst(t_philo_const *philo)
{
	t_philo_lst	*lst;
	t_cond		*philo_cond;

	lst = malloc(sizeof(t_philo_lst));
	philo_cond = malloc(sizeof(t_cond));
	philo_cond->death = 0;
	if (lst == NULL)
		return (NULL);
	lst->next = NULL;
	lst->prev = NULL;
	lst->kill = 0;
	lst->philo_const = philo;
	lst->philo_cond = philo_cond;
	lst->seat = 1;
	return (lst);
}

static int	lst_add_front(t_philo_lst *lst)
{
	t_philo_lst	*new;

	while (lst->next != NULL)
		lst = lst->next;
	new = malloc(sizeof(t_philo_lst));
	if (new == NULL)
		return (-1);
	lst->next = new;
	new->prev = lst;
	new->next = NULL;
	new->kill = 0;
	new->philo_const = lst->philo_const;
	new->philo_cond = lst->philo_cond;
	new->seat = lst->seat + 1;
	return (0);
}

static int	lst_add_last(t_philo_lst *lst)
{
	t_philo_lst	*new;

	new = malloc(sizeof(t_philo_lst));
	if (new == NULL)
		return (-1);
	new->next = lst;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
	new->prev = lst;
	new->kill = 0;
	new->philo_const = lst->philo_const;
	new->philo_cond = lst->philo_cond;
	new->seat = lst->seat + 1;
	return (0);
}

t_philo_lst	*create_lst(t_philo_const *philo)
{
	t_philo_lst	*philo_lst;
	long long	i;

	philo_lst = start_lst(philo);
	if (philo_lst == NULL)
		return (NULL);
	i = 1;
	while (i < philo->philos_num)
	{
		if (i++ == philo->philos_num - 1)
		{
			if (lst_add_last(philo_lst) == -1)
				return (NULL);
		}
		else
		{
			if (lst_add_front(philo_lst) == -1)
				return (NULL);
		}
	}
	return (philo_lst);
}
