#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*lst;
	
	while ((*begin_list) != NULL)
	{
		lst = (*begin_list)->next;
		if ((*cmp)((*begin_list)->data, data_ref) == 0)
		{
					lst = (*begin_list)->next;
		}
	}
}
