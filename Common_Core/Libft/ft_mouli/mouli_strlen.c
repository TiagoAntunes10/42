#include <stdio.h>
#include <string.h>
#include "libft.h"

void	mouli_strlen(void)
{
        char    *str;

        str = "Hello there";
		if (ft_strlen(str) != strlen(str))
		{
			printf("ft_strlen 'Hello there': %ld\n", ft_strlen(str));
			printf("strlen 'Hello there': %ld\n", strlen(str));
			return ;
		}
		str = "42";
		if (ft_strlen(str) != strlen(str))
		{
			printf("ft_strlen '42': %ld\n", ft_strlen(str));
			printf("strlen '42': %ld\n", strlen(str));
			return ;
		}
		str = "";
		if (ft_strlen(str) != strlen(str))
		{
			printf("ft_strlen '': %ld\n", ft_strlen(str));
			printf("strlen '': %ld\n", strlen(str));
			return ;
		}
		printf("ft_strlen: OK!\n");
}