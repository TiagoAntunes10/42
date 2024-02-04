/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:44:44 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/03 16:33:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **arr);
t_list	**create_lst(char **argv);
t_list	**sort_stc(t_list **stc_a, t_list **stc_b, int size);

int	main(int argc, char **argv)
{
	t_list	**stc_a;
	t_list	**stc_b;
	char	**stc;

	if (argc == 1)
		exit (1);
	else if (argc == 2)
		stc = ft_split(argv[1], ' ');
	if (argc == 2)
	{
		stc_a = create_lst(stc);
		free_array(stc);
	}
	else
		stc_a = create_lst(++argv);
	stc_b = NULL;
	if (check_duplicates(stc_a) == 1)
		print_error(stc_a, stc_b);
	stc_b = sort_stc(stc_a, stc_b, ft_lstsize(*stc_a));
	if (stc_b != NULL)
		finish_stc(stc_a, stc_b);
	if (checker(stc_a, stc_b) == 0)
		ft_printf("Not ordered!");
	ft_lstclear(stc_a);
	ft_lstclear(stc_b);
}

void	free_array(char **arr)
{
	int	i;
	
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// TODO: Remember to confirm cases when you have spaces and tabs
// before the number
t_list	**create_lst(char **argv)
{
	t_list	**lst;
	t_list	*node;
	int		nb;

	lst = malloc(sizeof(t_list **));
	while (*argv != NULL)
	{
		nb = ft_atoi(*argv);
		if (nb == 0 && ft_isalpha(*argv[0]) == 1)
			print_error(lst, NULL);
		else if (ft_strlen(*argv) > ft_nb_len(nb))
			print_error(lst, NULL);
		node = ft_lstnew(nb);
		argv++;
		ft_lstadd_back(lst, node);
	}
	return (lst);
}

t_list	**sort_stc(t_list **stc_a, t_list **stc_b, int size)
{
	int	pos;

	if (checker(stc_a, stc_b) == 1)
		return (NULL);
	if (size == 2)
	{
		swap(stc_a, 'a');
		return (NULL);
	}
	while (ft_lstsize(*stc_a) > 3)
	{
		if (stc_b == NULL)
		{
			stc_b = malloc(sizeof(t_list **));
			*stc_b = NULL;
			start_stc(stc_a, stc_b);
		}
		if (ft_lstsize(*stc_a) > 3)
		{
			pos = calc_cost(stc_a, stc_b);
			push_stc(stc_a, stc_b, pos);
		}
	}
	sort_small(stc_a);
	return (stc_b);
}
