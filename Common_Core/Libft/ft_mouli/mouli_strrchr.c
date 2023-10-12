#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_strrchr(void)
{
    char    *s;
	char	*sub;
	char	*sub2;
    char    c;
	int		i;

    s = "hfdb hnjnhdfb";
    c = 'n';
	sub = ft_strrchr(s, c);
	sub2 = strrchr(s, c);
	i = 0;
	while (sub[i] != '\0' || sub2[i] != '\0')
	{
		if (sub[i] != sub2[i])
		{
			printf("ft_strrchr_str 'njnhdfb': %s\n", sub);
			printf("strrchr_str 'njnhdfb': %s\n",  sub2);
			return ;
		}
		i++;
	}
	c = 'g';
	sub = ft_strrchr(s, c);
	sub2 = strrchr(s, c);
	if (sub != sub2)
	{
		printf("ft_strrchr_str 'NULL': %s\n", sub);
		printf("strrchr_str 'NULL': %s\n",  sub2);
		return ;
	}
	c = '\0';
	sub = ft_strrchr(s, c);
	sub2 = strrchr(s, c);
	if (*sub != *sub2)
	{
		printf("ft_strrchr_str '\\0': %s\n", sub);
		printf("strrchr_str '\\0': %s\n",  sub2);
		return ;
	}
	printf("ft_strrchr: OK!\n");
}