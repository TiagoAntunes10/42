/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:26:53 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/04 21:32:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	price_sep(t_list *lst, t_list *lst_b, int size_a, int size_b)
{
	if (lst->position <= size_a / 2 && lst_b->position > size_b / 2)
	{
		lst->price += lst_b->price;
		lst->fut_pos = lst_b->position;
	}
	else if (lst->position > size_a / 2 && lst_b->position <= size_b / 2)
	{
		lst->price += lst_b->price;
		lst->fut_pos = lst_b->position;
	}
	else if (lst->position > size_a / 2 && lst_b->position > size_b / 2)
	{
		if (lst->price < lst_b->price)
			lst->price = lst_b->price;
		lst->fut_pos = lst_b->position;
	}
	else if (lst->position <= size_a / 2 && lst_b->position <= size_b / 2)
	{
		if (lst->price < lst_b->price)
			lst->price = lst_b->price;
		lst->fut_pos = lst_b->position;
	}
}

static int	find_max(t_list *stc)
{
	int	i;
	int	max;
	int	max_pos;

	i = 1;
	max_pos = 0;
	max = stc->data;
	stc = stc->next;
	while (stc != NULL)
	{
		if (stc->data > max)
		{
			max_pos = i;
			max = stc->data;
		}
		i++;
		stc = stc->next;
	}
	return (max_pos);
}

// TODO: Add price_sep to this function
void	max_and_min(t_list *lst, t_list **stc_b, int size)
{
	lst->fut_pos = find_max(*stc_b);
	if (lst->fut_pos > size / 2)
		lst->price = size - lst->fut_pos;
	else
		lst->price = lst->fut_pos;
}
