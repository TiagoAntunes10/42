#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	mouli_isalnum(void)
{
	char	c;

	c = 'h';
	if (ft_isalnum(c) != isalnum(c))
	{
		printf("ft_isalnum 'h': %d\n", ft_isalnum(c));
		printf("isalnum 'h': %d\n", isalnum(c));
		return ;
	}
	c = 'H';
	if (ft_isalnum(c) != isalnum(c))
	{
		printf("ft_isalnum 'H': %d\n", ft_isalnum(c));
		printf("isalnum 'H': %d\n", isalnum(c));
		return ;
	}
	c = '3';
	if (ft_isalnum(c) != isalnum(c))
	{
		printf("ft_isalnum '3': %d\n", ft_isalnum(c));
		printf("isalnum '3': %d\n", isalnum(c));
		return ;
	}
	c = '\t';
	if (ft_isalnum(c) != isalnum(c))
	{
		printf("ft_isalnum '\\t': %d\n", ft_isalnum(c));
		printf("isalnum '\\t': %d\n", isalnum(c));
		return ;
	}
	c = '.';
	if (ft_isalnum(c) != isalnum(c))
	{
		printf("ft_isalnum '.': %d\n", ft_isalnum(c));
		printf("isalnum '.': %d\n", isalnum(c));
		return ;
	}
	printf("ft_isalnum: OK!\n");
}
