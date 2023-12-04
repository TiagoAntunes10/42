#include <stdio.h>
#include "libft.h"

static void	f(unsigned int n, char *s)
{
	(void) n;
	*s += 1;
}

void	mouli_striteri(void)
{
    char    s[5] = "35456";
	char	*d;
    
	d = "46567";
	ft_striteri(s, f);
	if (ft_memcmp(s, d, 5) != 0)
	{
		printf("ft_striteri '46567': %s\n", s);
		printf("check '46567': %s\n", d);
		return ;
	}
	printf("ft_striteri: OK!\n");
}