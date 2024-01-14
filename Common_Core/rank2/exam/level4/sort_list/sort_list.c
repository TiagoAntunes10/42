#include "sort_list.h"
#include <stdio.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		tmp;
	t_list	*lst_out;
	t_list	*lst_in;

	lst_out = lst;
	lst_out = lst;
	while (lst_out != NULL)
	{
		lst_in = lst_out->next;
		while (lst_in != NULL)
		{
			if ((*cmp)(lst_out->data, lst_in->data) == 0)
			{
				tmp = lst_out->data;
				lst_out->data = lst_in->data;
				lst_in->data = tmp;
			}
			lst_in = lst_in->next;
		}
		lst_out = lst_out->next;
	}
	return (lst);
}

int ascending(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list	*lst;
	t_list	ele1;
	t_list	ele2;
	t_list	ele3;
	t_list	ele4;
	t_list	ele5;
	t_list	ele6;

	(&ele1)->data = 6;
	(&ele1)->next = &ele2;
	(&ele2)->data = 6;
	(&ele2)->next = &ele3;
	(&ele3)->data = 1;
	(&ele3)->next = &ele4;
	(&ele4)->data = 3;
	(&ele4)->next = &ele5;
	(&ele5)->data = 2;
	(&ele5)->next = &ele6;
	(&ele6)->data = 7;
	(&ele6)->next = NULL;
	lst = &ele1;
	lst = sort_list(lst, ascending);
	while (lst != NULL)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}
