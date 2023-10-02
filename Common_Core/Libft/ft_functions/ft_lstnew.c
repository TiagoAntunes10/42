#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	lst1;
	t_list			*lst;

	lst1.content = content;
	lst1.next = NULL;
	lst = &lst1;
	return (lst);
}

/*
#include <stdio.h>

int	main(void)
{
	struct s_list	lst;
	t_list			*lst1;
	char			*str;

	str = "ashdb";
	lst1 = &lst;
	lst1 = ft_lstnew(str);
	printf("%s\n", (char *) (*lst1).content);
}*/