#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	mouli_substr(void)
{
	char	*sub;
	char	*phrase;
	char	*check;

	phrase = "Hello there";
	check = "there";
	sub = ft_substr(phrase, 6, 5);
	if (ft_memcmp(sub, check, 5) != 0)
	{
			printf("ft_substr 'there': %s\n", sub);
			printf("check 'there': %s\n", check);
			return ;
	}
	free(sub);
    phrase = "Hello there";
	check = "e";
	sub = ft_substr(phrase, 10, 5);
	if (ft_memcmp(sub, check, 5) != 0)
	{
			printf("ft_substr 'e': %s\n", sub);
			printf("check 'e': %s\n", check);
			return ;
	}
	free(sub);
	printf("ft_substr: OK!\n");
}