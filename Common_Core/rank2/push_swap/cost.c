/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:07:28 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/02 21:00:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_cost(t_list **stc)
{
	t_list	*lst;
	int		i;
	int		size;

	i = 0;
	lst = *stc;
	size = ft_lstsize(*stc);
	while (lst != NULL)
	{
		if (i > size / 2)
			lst->price = size - i;
		else
			lst->price = i;
		lst->position = i;
		i++;
		lst = lst->next;
	}
}

static void	sum_cost(t_list *lst, t_list **stc_b)
{
	t_list	*lst_b;

	lst_b = *stc_b;
	while (lst_b->next != NULL)
	{
		if (lst->data < lst_b->data && lst->data > lst_b->next->data)
		{
			lst->price += lst_b->next->price;
			lst->fut_pos = lst_b->next->position;
			return ;
		}
		if (lst->data < lst_b->data && lst_b->data > lst_b->next->data)
		{
			lst->price += lst_b->next->price;
			lst->fut_pos = lst_b->next->position;
			return ;
		}
		lst_b = lst_b->next;
	}
	lst->fut_pos = 0;
}

int	calc_cost(t_list **stc_a, t_list **stc_b)
{
	t_list	*lst;
	int		min;

	lst = (*stc_a);
	get_cost(stc_a);
	get_cost(stc_b);
	min = lst->price;
	while (lst != NULL)
	{
		sum_cost(lst, stc_b);
		if (lst->price < min)
			min = lst->price;
		lst = lst->next;
	}
	return (min);
}
