/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:36:15 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/30 22:00:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_list **lst_a, t_list **lst_b)
{
	ft_printf("Error\n");
	if ((*lst_b) != NULL)
		ft_lstclear(lst_b);
	ft_lstclear(lst_a);
	exit(1);
}

int	ft_nb_len(int nb)
{
	int	l;

	l = 1;
	if (nb < 0)
		nb *= -1;
	while (nb / 10 > 0)
	{
		l++;
		nb /= 10;
	}
	return (l);
}

void	division(t_list **stc_a, t_list **stc_b, int size)
{
	t_list	*stc_a_next;
	int		i;

	i = 0;
	while (i < size / 2)
	{
		stc_a_next = (*stc_a)->next;
		if (stc_a_next->data < (*stc_a)->data)
			swap(stc_a, 'a');
		else if (stc_a_next->data == (*stc_a)->data)
			print_error(stc_a, stc_b);
		push(stc_b, stc_a, 'b');
	}
}

// TODO: Create sort_both, sort_a and sort_b functions
void	order_stc(t_list **stc_a, t_list **stc_b, int size)
{
	int		i;
	t_list	*stc_a_next;
	t_list	*stc_b_next;

	if (checker(stc_a, 'a') == 0 && checker(stc_b, 'b') == 0)
		sort_both(stc_a, stc_b);
	else if (checker(stc_a, 'a') == 0)
		sort_a(stc_a);
	else if (checker(stc_b, 'b') == 0)
		sort_b(stc_b);
	i = 0;
	while (i < size / 4)
	{
		stc_a_next = (*stc_a)->next;
		stc_b_next = (*stc_b)->next;
		if (stc_b_next->data > (*stc_b)->data &&
			stc_a_next->data < (*stc_a)->data)
			swap_ss(stc_a, stc_b);
		else if (stc_a_next->data < (*stc_a)->data)
			swap(stc_a, 'a');
		else if (stc_a_next->data == (*stc_a)->data)
			print_error(stc_a, stc_b);
		if (stc_b_next->data > (*stc_b)->data)
			swap(stc_b, 'b');
		rotate_ss(stc_a, stc_b);
	}
	while (i < size / 4 && checker(stc_a, 'a') == 0 && checker(stc_b, 'b') == 0)
		rev_rotate_ss(stc_a, stc_b);
}

// TODO: Implement new sorting algorithm drawn in the tablet
void	rev_division(t_list **stc_a, t_list **stc_b, int size)
{
	t_list	*stc_a_next;
	t_list	*stc_b_next;
	
	push(stc_a, stc_b, 'a');
	while ((*stc_b) != NULL)
	{
		stc_a_next = (*stc_a)->next;
		if (stc_a_next->data < (*stc_a)->data)
		{
			swap(stc_a, 'a');
			if ((*stc_a)->data < (*stc_b)->data)
				push(stc_b, stc_a, 'b');
		}
		push(stc_a, stc_b, 'a');
	}
}
