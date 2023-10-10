#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "libft.h"

void	mouli_itoa(void)
{
	int					n;
	char				*str;
	char				*toa;
	struct mallinfo2	info2;

	n = -2147483648;
	str = "-2147483648";
	toa = ft_itoa(n);
	info2 = mallinfo2();
	if (info2.keepcost != 0)
		printf("ft_itoa: Memory leaks -> %ld bytes!\n", info2.keepcost);
	if (strcmp(str, toa) != 0)
	{
		printf("ft_itoa: '-2147483648': %s\n", toa);
		printf("itoa: '-2147483648': %s\n", str);
	}
	n = 2147483647;
	str = "2147483647";
	toa = ft_itoa(n);
	info2 = mallinfo2();
	if (info2.keepcost != 0)
		printf("ft_itoa: Memory leaks -> %ld bytes!\n", info2.keepcost);
	if (strcmp(str, toa) != 0)
	{
		printf("ft_itoa: '2147483647': %s\n", toa);
		printf("itoa: '2147483647': %s\n", str);
	}
	n = 657;
	str = "657";
	toa = ft_itoa(n);
	info2 = mallinfo2();
	if (info2.keepcost != 0)
		printf("ft_itoa: Memory leaks -> %ld bytes!\n", info2.keepcost);
	if (strcmp(str, toa) != 0)
	{
		printf("ft_itoa: '657': %s\n", toa);
		printf("itoa: '657': %s\n", str);
	}
	free(toa);
	printf("ft_itoa: OK!\n");
}