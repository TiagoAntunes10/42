/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:36:15 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/08 16:50:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_list **lst_a, t_list **lst_b)
{
	write(2, "Error\n", 6);
	if (lst_b != NULL)
		ft_lstclear(lst_b);
	ft_lstclear(lst_a);
	exit(1);
}

int	ft_nb_len(int nb)
{
	int	l;

	l = 1;
	if (nb < 0)
	{
		nb *= -1;
		l++;
	}
	while (nb / 10 > 0)
	{
		l++;
		nb /= 10;
	}
	return (l);
}

void	start_stc(t_list **stc_a, t_list **stc_b)
{
	int		i;

	i = 0;
	while (i < 2 && ft_lstsize(*stc_a) > 3)
	{
		push(stc_b, stc_a, 'b');
		i++;
	}
}

int	get_fut(t_list **stc, int pos)
{
	t_list	*lst;
	int		i;

	lst = *stc;
	i = 0;
	while (i < pos)
	{
		lst = lst->next;
		i++;
	}
	return (lst->fut_pos);
}
