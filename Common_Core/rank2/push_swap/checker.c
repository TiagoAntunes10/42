/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:25:37 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/02 20:17:15 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_list **stc_a, t_list **stc_b)
{
	t_list	*lst;
	t_list	*stc_next;

	lst = (*stc_a);
	stc_next = lst->next;
	while (stc_next != NULL)
	{
		if (stc_next->data < lst->data)
			return (0);
		else if (stc_next->data == lst->data)
			print_error(stc_a, stc_b);
		lst = lst->next;
		stc_next = lst->next;
	}
	return (1);
}
