/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:25:37 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/30 21:33:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_list **stc, char c)
{
	t_list	*stc_next;

	stc_next = (*stc)->next;
	if (c == 'a')
	{
		while (stc_next != NULL)
		{
			if (stc_next->data < (*stc)->data)
				return (0);
			stc_next = (*stc)->next;
		}
	}
	else
	{
		while (stc_next != NULL)
		{
			if (stc_next->data > (*stc)->data)
				return (0);
			stc_next = (*stc)->next;
		}
	}
	return (1);
}

void	check_top(t_list **stc, char c)
{
	int		top;
	t_list	*stc_next;

	top = (*stc)->data;
	while (stc_next != NULL)
	{
		if (c == 'a')
		{

		}
	} 
}
