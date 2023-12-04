#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_memset(void)
{
	char            str[] = "Hello there";
    char            str2[] = "Hello there";
	char			*str3;
	char			*str4;
    unsigned int    n;
    int             arr[7];
    int             arr2[7];
    unsigned int    i;
	int				c;

    n = 2;
	c = 65;
    ft_memset(str + 7, c, n);
    memset(str2 + 7, c, n);
	i = 0;
	if (ft_memcmp(str, str2, 11) != 0)
	{
    	printf("ft_memset 'Hello there': %s\n", str);
    	printf("memset 'Hello there': %s\n", str2);
		return ;
	}
	c = 84;
	str3 = ft_memset(str + 3, c, n);
    str4 = memset(str2 + 3, c, n);
	i = 0;
	if (ft_memcmp(str3, str4, 8) != 0)
	{
    	printf("ft_memset 'lo tAAre': %s\n", str3);
    	printf("memset 'lo tAAre': %s\n", str4);
		return ;
	}
	n = 7;
    ft_memset(arr, c, n * sizeof(int));
    memset(arr2, c, n * sizeof(int));
	if (ft_memcmp(arr, arr2, n * sizeof(int)) != 0)
	{
		i = 0;
		printf("ft_memset_arr: ");
		while (i < n)
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf("\nmemset_arr: ");
		i = 0;
		while (i < n)
		{
			printf("%d ", arr2[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	printf("ft_memset: OK!\n");
}