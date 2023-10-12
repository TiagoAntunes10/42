#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_strdup(void)
{
	char			*dest;
	char			*dest2;
    char            *src;

    src = "Hello there";
	dest = ft_strdup(src);
	dest2 = strdup(src);
	if (memcmp(dest, dest2, 7) != 0)
	{
		printf("ft_strdup_str 'Hello there': %s\n", dest);
		printf("strdup_str 'Hello there': %s\n", dest2);
		return ;
	}
	free(dest);
	free(dest2);
	printf("ft_strdup: OK!\n");
}