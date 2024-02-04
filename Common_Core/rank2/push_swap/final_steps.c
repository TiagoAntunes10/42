/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:12:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/03 18:27:57 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_top(t_list *stc_a)
{
	int	i;
	int	min;
	int	min_pos;

	i = 1;
	min_pos = 0;
	min = stc_a->data;
	stc_a = stc_a->next;
	while (stc_a != NULL)
	{
		if (stc_a->data < min)
		{
			min_pos = i;
			min = stc_a->data;
		}
		i++;
		stc_a = stc_a->next;
	}
	return (min_pos);
}

static int	find_pos(t_list **stc_a, t_list *stc_b)
{
	t_list	*lst;
	int		i;

	lst = *stc_a;
	i = 0;
	while (lst->next != NULL)
	{
		if (lst->data < stc_b->data && lst->next->data > stc_b->data)
			return (i + 1);
		lst = lst->next;
		i++;
	}
	if (stc_b->data < (*stc_a)->data && stc_b->data > lst->data)
		return (0);
	return (find_top(*stc_a));
}


static void	top_value(t_list **stc_a)
{
	int	pos;
	int	size;

	pos = find_top(*stc_a);
	size = ft_lstsize(*stc_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(stc_a, 'a');
	}
	else
	{
		while (pos++ < size)
			rev_rotate(stc_a, 'a');
	}
}

void	finish_stc(t_list **stc_a, t_list **stc_b)
{
	int	pos;
	int	size;

	while (*stc_b != NULL)
	{
		pos = find_pos(stc_a, *stc_b);
		size = ft_lstsize(*stc_a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rotate(stc_a, 'a');
		}
		else
		{
			while (pos++ < size)
				rev_rotate(stc_a, 'a');
		}
		push(stc_a, stc_b, 'a');
	}
	top_value(stc_a);
}
