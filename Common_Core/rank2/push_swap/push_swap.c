/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:44:44 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/31 22:29:35 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**create_lst(int argc, char **argv);
void	sort_stc(t_list **stc_a, int size);

// TODO: Add case with only one argument, using split to get all the arguments
int	main(int argc, char **argv)
{
	t_list	**stc_a;

	if (argc == 1)
		exit (1);
	stc_a = NULL;
	stc_a = create_lst(argc, argv);
	sort_stc(stc_a, ft_lstsize(*stc_a));
}

// TODO: Remember to confirm cases when you have spaces and tabs before the number
t_list	**create_lst(int argc, char **argv)
{
	t_list	**lst;
	t_list	*node;
	int		nb;

	lst = NULL;
	while (--argc != 0)
	{
		nb = ft_atoi(argv[argc]);
		if (nb == 0 && ft_isalpha(argv[argc][0]) == 1)
			print_error(lst, NULL);
		else if (ft_strlen(argv[argc]) > ft_nb_len(nb))
			print_error(lst, NULL);
		node = ft_lstnew(nb);
		ft_lstadd_front(lst, node);
		ft_lstdelone(node);
	}
	return (lst);
}

void	sort_stc(t_list **stc_a, int size)
{
	t_list	**stc_b;

	if (checker(stc_a, 'a') == 1)
	{
		ft_printf("\n");
		return ;
	}
	if (size <= 3)
	{
		sort_small(stc_a);
		return ;
	}
	(*stc_b) = NULL;
	division(stc_a, stc_b, size);
	order_stc(stc_a, stc_b, size);
	rev_division(stc_a, stc_b, size);
}
