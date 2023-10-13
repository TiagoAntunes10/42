#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	mouli_tolower(void)
{
        char    c;

        c = 'h';
		if (ft_tolower(c) != tolower(c))
		{
			printf("ft_tolower 'h': %d\n", ft_tolower(c));
			printf("tolower 'h': %d\n", tolower(c));
			return ;
		}
		c = 'H';
		if (ft_tolower(c) != tolower(c))
		{
			printf("ft_tolower 'H': %d\n", ft_tolower(c));
			printf("tolower 'H': %d\n", tolower(c));
			return ;
		}
		c = '3';
		if (ft_tolower(c) != tolower(c))
		{
			printf("ft_tolower '3': %d\n", ft_tolower(c));
			printf("tolower '3': %d\n", tolower(c));
			return ;
		}
		c = '\t';
		if (ft_tolower(c) != tolower(c))
		{
			printf("ft_tolower '\\t': %d\n", ft_tolower(c));
			printf("tolower '\\t': %d\n", tolower(c));
			return ;
		}
		printf("ft_tolower: OK!\n");
}