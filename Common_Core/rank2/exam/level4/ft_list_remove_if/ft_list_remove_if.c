#include <stdlib.h>
#include "ft_list.h"

void	remove_lst(t_list **lst);
int		cmp(void *a, void *b);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*lst;
	t_list	*lst_before;
	int		i;
	
	i = 0;
	lst_before = (*begin_list);
	lst = lst_before->next;
	while (lst != NULL)
	{
		if ((*cmp)(lst_before->data, data_ref) == 0 && i == 0)
		{
			free(lst_before->data);
			(*begin_list) = (*begin_list)->next;
			free(lst_before);
			lst_before = (*begin_list);
			lst = lst_before->next;
			continue ;
		}
		if ((*cmp)(lst->data, data_ref) == 0)
			remove_lst(&lst_before);
		lst_before = lst_before->next;
		if (lst_before != NULL)
			lst = lst_before->next;
		else
			lst = NULL;
		i++;
	}
}

void	remove_lst(t_list **lst)
{
	t_list	*lst_next;

	lst_next = (*lst)->next;
	free(lst_next->data);
	(*lst)->next = lst_next->next;
	free(lst_next);
}

int	cmp(void *a, void *b)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = a;
	str2 = b;
	while (*str1 != 0 && *str2 != 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	t_list	*ele1;
	t_list	*ele2;
	t_list	*ele3;
	t_list	*ele4;
	t_list	*ele5;
	t_list	*ele6;
	t_list	**begin_lst;
	int		ref;
	int		*i1;
	int		*i2;
	int		*i3;
	int		*i4;
	int		*i5;
	int		*i6;


	ele1 = malloc(sizeof(t_list));
	ele2 = malloc(sizeof(t_list));
	ele3 = malloc(sizeof(t_list));
	ele4 = malloc(sizeof(t_list));
	ele5 = malloc(sizeof(t_list));
	ele6 = malloc(sizeof(t_list));
	i1 = malloc(sizeof(int *));
	i2 = malloc(sizeof(int *));
	i3 = malloc(sizeof(int *));
	i4 = malloc(sizeof(int *));
	i5 = malloc(sizeof(int *));
	i6 = malloc(sizeof(int *));
	*i1 = 6;
	*i2 = 6;
	*i3 = 3;
	*i4 = 1;
	*i5 = 2;
	*i6 = 7;
	ele1->data = i1;
	ele1->next = ele2;
	ele2->data = i2;
	ele2->next = ele3;
	ele3->data = i3;
	ele3->next = ele4;
	ele4->data = i4;
	ele4->next = ele5;
	ele5->data = i5;
	ele5->next = ele6;
	ele6->data = i6;
	ele6->next = NULL;
	begin_lst = &ele1;
	ref = 7;
	ft_list_remove_if(begin_lst, &ref, cmp);
	while ((*begin_lst) != NULL)
	{
		printf("%d\n", *((int *) (*begin_lst)->data));
		(*begin_lst) = (*begin_lst)->next;
	}
}
