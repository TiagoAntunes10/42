/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:25:37 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/03 14:55:36 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft/libft.h"
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

int	check_duplicates(t_list **stc)
{
	t_list	*lst;
	t_list	*lst_next;
	int		data;

	lst = (*stc);
	while (lst != NULL)
	{
		lst_next = lst->next;
		data = lst->data;
		while (lst_next != NULL)
		{
			if (data == lst_next->data)
				return (1);
			lst_next = lst_next->next;
		}
		lst = lst->next;
	}
	return (0);
}
