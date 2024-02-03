/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:58:38 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/03 06:33:44 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_list **stc)
{
	int		top;
	int		mid;
	int		bot;

	top = (*stc)->data;
	mid = (*stc)->next->data;
	bot = (*stc)->next->next->data;
	if (top > mid && top > bot && mid < bot)
		rotate(stc, 'a');
	else if (top > mid && top < bot && mid < bot)
		swap(stc, 'a');
	else if (top > mid && top < bot && mid > bot)
	{
		rotate(stc, 'a');
		swap(stc, 'a');
	}
	else if (top < mid && top > bot && mid > bot)
		rev_rotate(stc, 'a');
	else if (top < mid && top < bot && mid > bot)
	{
		swap(stc, 'a');
		rotate(stc, 'a');
	}
}

void	push_stc(t_list **stc_a, t_list **stc_b, int cost, int pos)
{
	int	i;
	int	fut;
	int	size_a;
	int	size_b;

	fut = get_fut(stc_a, pos);
	size_a = ft_lstsize(*stc_a);
	size_b = ft_lstsize(*stc_b);
	i = 0;
	while (i <= cost)
	{
		if (pos == 0 && fut > 0)
		{
			if (fut + i > size_b / 2)
			{
				while (fut + i < size_b--)
					rev_rotate(stc_b, 'b');
			}
			else if (fut - i <= size_b / 2)
			{
				while (fut-- > 0)
					rotate(stc_b, 'b');
			}
		}
		else if (pos > 0 && fut == 0)
		{
			if (pos + i > size_a / 2)
			{
				while (pos + i < size_a--)
					rev_rotate(stc_a, 'a');
			}
			else if (pos - i <= size_a / 2)
			{
				while (pos-- > 0)
					rotate(stc_a, 'a');
			}
		}
		else if (pos + i > size_a / 2 && fut + i > size_b / 2)
			rev_rotate_ss(stc_a, stc_b);
		else if (pos + i > size_a / 2 || fut + i > size_b / 2)
		{
			while (pos + i < size_a--)
				rev_rotate(stc_a, 'a');
			while (fut + i < size_b--)
				rev_rotate(stc_b, 'b');
		}
		else if (pos - i <= (size_a / 2) && fut - i <= (size_b / 2))
			rotate_ss(stc_a, stc_b);
		else if (pos - i <= (size_a / 2) || fut - i <= (size_b / 2))
		{
			while (pos-- > 0)
				rotate(stc_a, 'a');
			while (fut-- > 0)
				rotate(stc_b, 'b');
		}
		i++;
	}
	push(stc_b, stc_a, 'b');
}
