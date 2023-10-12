#include <stdio.h>
#include "libft.h"

static char	f(unsigned int n, char s)
{
	(void) n;
	return (s + 32);
}

void	mouli_strmapi(void)
{
    char    *s = "HASVHSV";
	char	*check;
	char	*d;

    
	check = "hasvhsv";
	d = ft_strmapi(s, f);
	if (ft_memcmp(d, check, 5) != 0)
	{
		printf("ft_strmapi 'hasvhsv': %s\n", d);
		printf("check 'hasvhsv': %s\n", check);
		return ;
	}
	free(d);
	printf("ft_strmapi: OK!\n");
}