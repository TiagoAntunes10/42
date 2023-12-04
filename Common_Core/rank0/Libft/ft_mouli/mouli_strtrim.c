#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	mouli_strtrim(void)
{
	char	*words;
	char	*phrase;
	char	*check;
	char	*c;

	phrase = " ... .. . sdhj.d.s .hj.dhd. .. ..";
	c = " .";
	check = "sdhj.d.s .hj.dhd";
	words = ft_strtrim(phrase, c);
	if (ft_memcmp(words, check, 16) != 0)
	{
			printf("ft_strtrim 'sdhj.d.s .hj.dhd': %s\n", words);
			printf("check 'sdhj.d.s .hj.dhd': %s\n", check);
			return ;
	}
	free(words);
	printf("ft_strtrim: OK!\n");
}