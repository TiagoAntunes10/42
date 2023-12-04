#include <stdio.h>
#include "libft.h"

void	mouli_strjoin(void)
{
	char	*str;
	char	*str1;
	char	*str2;
	char	*check;

	str1 = "Hello ";
	str2 = "there";
	check = "Hello there";
	str = ft_strjoin(str1, str2);
	if (ft_memcmp(str, check, 11) != 0)
	{
		printf("ft_strjoin 'Hello there': %s\n", str);
		printf("Check 'Hello there': %s\n", check);
		return ;
	}
	free(str);
	printf("ft_strjoin: OK!\n");
}