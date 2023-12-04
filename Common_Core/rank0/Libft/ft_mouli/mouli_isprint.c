#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	mouli_isprint(void)
{
	char	c;

	c = ' ';
	if (ft_isprint(c) != isprint(c))
	{
		printf("ft_isprint ' ': %d\n", ft_isprint(c));
		printf("isprint ' ': %d\n", isprint(c));
		return ;
	}
	c = '~';
	if (ft_isprint(c) != isprint(c))
	{
		printf("ft_isprint '~': %d\n", ft_isprint(c));
		printf("isprint '~': %d\n", isprint(c));
		return ;
	}
	c = '\n';
	if (ft_isprint(c) != isprint(c))
	{
		printf("ft_isprint '\\n': %d\n", ft_isprint(c));
		printf("isprint '\\n': %d\n", isprint(c));
		return ;
	}
	c = '\t';
	if (ft_isprint(c) != isprint(c))
	{
		printf("ft_isprint '\\t': %d\n", ft_isprint(c));
		printf("isprint '\\t': %d\n", isprint(c));
		return ;
	}
	c = 127;
	if (ft_isprint(c) != isprint(c))
	{
		printf("ft_isprint 127: %d\n", ft_isprint(c));
		printf("isprint 127: %d\n", isprint(c));
		return ;
	}
	printf("ft_isprint: OK!\n");
}