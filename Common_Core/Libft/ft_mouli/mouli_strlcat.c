#include "libft.h"
#include <stdio.h>

void	mouli_strlcat(void)
{
	char	dest[20] = "Hello";
	char	*src;
	char	*check;
	int		n;

	src = " there";
	check = "Hello there";
	n = ft_strlcat(dest, src, 12);
	if (ft_memcmp(dest, check, 11) != 0 || n != 11)
	{
		printf("ft_strlcat 'Hello there' '11': %s %d\n", dest, n);
		printf("Check 'Hello there' '11': %s 11\n", check);
		return ;
	}
	check = "Hello there";
	n = ft_strlcat(dest, src, 11);
	if (ft_memcmp(dest, check, 11) != 0 || n != 17)
	{
		printf("ft_strlcat 'Hello there' '17': %s %d\n", dest, n);
		printf("Check 'Hello there' '17': %s 17\n", check);
		return ;
	}
	check = "Hello there th";
	n = ft_strlcat(dest, src, 15);
	if (ft_memcmp(dest, check, 14) != 0 || n != 17)
	{
		printf("ft_strlcat 'Hello there th' '17': %s %d\n", dest, n);
		printf("Check 'Hello there th' '17': %s 17\n", check);
		return ;
	}
	printf ("ft_strlcat: OK!\n");
}