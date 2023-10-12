#include <stdio.h>
#include <string.h>
#include "libft.h"

void	mouli_itoa(void)
{
	int					n;
	char				*str;
	char				*toa;

	n = -2147483648;
	str = "-2147483648";
	toa = ft_itoa(n);
	if (strcmp(str, toa) != 0)
	{
		printf("ft_itoa: '-2147483648': %s\n", toa);
		printf("itoa: '-2147483648': %s\n", str);
	}
	n = 2147483647;
	free(toa);
	str = "2147483647";
	toa = ft_itoa(n);
	if (strcmp(str, toa) != 0)
	{
		printf("ft_itoa: '2147483647': %s\n", toa);
		printf("itoa: '2147483647': %s\n", str);
	}
	n = 0;
	free(toa);
	str = "0";
	toa = ft_itoa(n);
	if (strcmp(str, toa) != 0)
	{
		printf("ft_itoa: '0': %s\n", toa);
		printf("itoa: '0': %s\n", str);
	}
	free(toa);
	printf("ft_itoa: OK!\n");
}