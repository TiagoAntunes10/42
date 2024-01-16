#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

void	f(void *data)
{
	unsigned char	*value;

	value = data;
	while (*value != 0)
	{
		*value += 1;
		value++;
	}
	value++;
}

int	main(void)
{
	t_list	*ele1;
	t_list	*ele2;
	t_list	*ele3;
	t_list	*ele4;
	t_list	*ele5;
	t_list	*ele6;
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
	ft_list_foreach(ele1, f);
	while (ele1 != NULL)
	{
		printf("%d\n", *((int *) ele1->data));
		ele1 = ele1->next;
	}
}
