#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	mouli_isalpha(void)
{
        char    c;

        c = 'h';
		if (ft_isalpha(c) != isalpha(c))
		{
			printf("ft_isalpha 'h': %d\n", ft_isalpha(c));
			printf("isalpha 'h': %d\n", isalpha(c));
			return ;
		}
		c = 'H';
		if (ft_isalpha(c) != isalpha(c))
		{
			printf("ft_isalpha 'H': %d\n", ft_isalpha(c));
			printf("isalpha 'H': %d\n", isalpha(c));
			return ;
		}
		c = '3';
		if (ft_isalpha(c) != isalpha(c))
		{
			printf("ft_isalpha '3': %d\n", ft_isalpha(c));
			printf("isalpha '3': %d\n", isalpha(c));
			return ;
		}
		c = '\t';
		if (ft_isalpha(c) != isalpha(c))
		{
			printf("ft_isalpha '\\t': %d\n", ft_isalpha(c));
			printf("isalpha '\\t': %d\n", isalpha(c));
			return ;
		}
		printf("ft_isalpha: OK!\n");
}