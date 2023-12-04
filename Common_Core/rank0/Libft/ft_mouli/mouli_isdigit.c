#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	mouli_isdigit(void)
{
	char	c;

	c = '0';
	if (ft_isdigit(c) != isdigit(c))
	{
		printf("ft_isdigit '0': %d\n", ft_isdigit(c));
		printf("isdigit '0': %d\n", isdigit(c));
		return ;
	}
	c = '9';
	if (ft_isdigit(c) != isdigit(c))
	{
		printf("ft_isdigit '9': %d\n", ft_isdigit(c));
		printf("isdigit '9': %d\n", isdigit(c));
		return ;
	}
	c = 'd';
	if (ft_isdigit(c) != isdigit(c))
	{
		printf("ft_isdigit 'd': %d\n", ft_isdigit(c));
		printf("isdigit 'd': %d\n", isdigit(c));
		return ;
	}
	c = '\t';
	if (ft_isdigit(c) != isdigit(c))
	{
		printf("ft_isdigit '\\t': %d\n", ft_isdigit(c));
		printf("isdigit '\\t': %d\n", isdigit(c));
		return ;
	}
	c = '.';
	if (ft_isdigit(c) != isdigit(c))
	{
		printf("ft_isdigit '.': %d\n", ft_isdigit(c));
		printf("isdigit '.': %d\n", isdigit(c));
		return ;
	}
	printf("ft_isdigit: OK!\n");
}