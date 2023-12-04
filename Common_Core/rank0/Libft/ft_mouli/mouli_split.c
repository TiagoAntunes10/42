#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	mouli_split(void)
{
	char	**words;
	char	*phrase;
	char	**check;
	char	c;
	int		i;

	phrase = "Hello there";
	c = ' ';
	words = ft_split(phrase, c);
	check = malloc(2 * sizeof(char *));
	check[0] = "Hello";
	check[1] = "there";
	i = 0;
	while (i < 2)
	{
		if (ft_memcmp(words[i], check[i], 5) != 0)
		{
			printf("ft_split: %s\n", words[i]);
			printf("check: %s\n", check[i]);
			return ;
		}
		free(words[i]);
		i++;
	}
	free(check);
	free(words);
	printf("ft_split: OK!\n");
}