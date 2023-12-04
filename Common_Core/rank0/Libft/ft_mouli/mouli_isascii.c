#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	mouli_isascii(void)
{
	int	c;

	c = 64;
	if (ft_isascii(c) != isascii(c))
	{
		printf("ft_isascii 64: %d\n", ft_isascii(c));
		printf("isascii 64: %d\n", isascii(c));
		return ;
	}
	c = 765;
	if (ft_isascii(c) != isascii(c))
	{
		printf("ft_isascii 765: %d\n", ft_isascii(c));
		printf("isascii 765: %d\n", isascii(c));
		return ;
	}
	c = 0;
	if (ft_isascii(c) != isascii(c))
	{
		printf("ft_isascii 0: %d\n", ft_isascii(c));
		printf("isascii 0: %d\n", isascii(c));
		return ;
	}
	c = 130;
	if (ft_isascii(c) != isascii(c))
	{
		printf("ft_isascii 130: %d\n", ft_isascii(c));
		printf("isascii 130: %d\n", isascii(c));
		return ;
	}
	c = 127;
	if (ft_isascii(c) != isascii(c))
	{
		printf("ft_isascii 127: %d\n", ft_isascii(c));
		printf("isascii 127: %d\n", isascii(c));
		return ;
	}
	printf("ft_isascii: OK!\n");
}