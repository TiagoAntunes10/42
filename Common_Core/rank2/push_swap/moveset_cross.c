/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:07:42 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/30 16:01:59 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_rec, t_list **lst_giv, char stack)
{
	t_list	*lst_tmp;

	lst_tmp = (*lst_giv)->next;
	ft_lstadd_front(lst_rec, (*lst_giv));
	*lst_giv = lst_tmp;
	ft_printf("p%c\n", stack);
}
