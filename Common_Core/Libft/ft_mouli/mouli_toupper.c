#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	mouli_toupper(void)
{
        char    c;

        c = 'h';
		if (ft_toupper(c) != toupper(c))
		{
			printf("ft_toupper 'h': %d\n", ft_toupper(c));
			printf("toupper 'h': %d\n", toupper(c));
			return ;
		}
		c = 'H';
		if (ft_toupper(c) != toupper(c))
		{
			printf("ft_toupper 'H': %d\n", ft_toupper(c));
			printf("toupper 'H': %d\n", toupper(c));
			return ;
		}
		c = '3';
		if (ft_toupper(c) != toupper(c))
		{
			printf("ft_toupper '3': %d\n", ft_toupper(c));
			printf("toupper '3': %d\n", toupper(c));
			return ;
		}
		c = '\t';
		if (ft_toupper(c) != toupper(c))
		{
			printf("ft_toupper '\\t': %d\n", ft_toupper(c));
			printf("toupper '\\t': %d\n", toupper(c));
			return ;
		}
		printf("ft_toupper: OK!\n");
}