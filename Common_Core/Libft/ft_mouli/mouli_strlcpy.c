#include "libft.h"
#include <stdio.h>

void	mouli_strlcpy(void)
{
	char	dest[20] = "Hello";
	char	*src;
	char	*check;
	int		n;

	src = "Hello there";
	check = "Hello there";
	n = ft_strlcpy(dest, src, 12);
	if (ft_memcmp(dest, check, 12) != 0 || n != 11)
	{
		printf("ft_strlcpy 'Hello there' '11': %s %d\n", dest, n);
		printf("Check 'Hello there' '11': %s 11\n", check);
		return ;
	}
	check = "Hello there";
	n = ft_strlcpy(dest, src, 7);
	if (ft_memcmp(dest, check, 6) != 0 || n != 11)
	{
		printf("ft_strlcpy 'Hello there' '11': %s %d\n", dest, n);
		printf("Check 'Hello there' '11': %s 11\n", check);
		return ;
	}
	printf ("ft_strlcpy: OK!\n");
}