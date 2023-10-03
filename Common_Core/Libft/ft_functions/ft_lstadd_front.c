/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:47:37 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:47:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	int	i;

	i = 0;
	while ((**lst).next != NULL)
	{
		*lst = (**lst).next;
		i++;
	}
	while (i >= 0)
	{
		lst[i + 1] = lst[i];
		i--;
	}
	lst[0] = new;
}

#include <stdio.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst1;
	t_list	lst2;
	t_list	*new;
	t_list	new1;
	int		i;

	lst1 = &lst2;
	lst = &lst1;
	new = &new1;
	(*lst[0]).content = "aaaaaa";
	(*lst[0]).next = lst[1];
	(*lst[1]).content = "bbbbbb";
	(*lst[1]).next = lst[2];
	(*lst[2]).content = "cccccc";
	(*lst[2]).next = NULL;
	(*new).content = "dddddd";
	ft_lstadd_front(lst, new);
	i = 0;
	while (i < 4)
	{
		printf("%s\n", (char *) (*lst[i]).content);
		i++;
	}
}
