#include <stdio.h>
#include "libft.h"

void	mouli_lstnew(void)
{
	struct s_list	lst;
	t_list			*lst1;
	char			*str;
    char			*str2;

	str = "Hello there";
	lst1 = &lst;
	lst1 = ft_lstnew(str);
    str2 = (char *)  (*lst1).content;
    if (ft_strncmp(str, str2, 11) != 0)
	{
		printf("ft_lstnew 'Hello there': %s\n", str2);
		printf("Check 'Hello there': %s\n", str);
	}
	if (lst1->next != NULL)
	{
		
	}
	free(lst1->content);
	free(lst1);
	printf("ft_lstnew: OK!\n");
}