#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_memmove(void)
{
    char            dest[100];
    char            dest2[100];
	char			*dest3;
	char			*dest4;
    char            *src;
    unsigned int    n;
    int             arr[5];
	int             arr3[5];
	int const       arr2[5] = {88, 5, 3, 6, 5};
    unsigned int    i;

    src = "Hello there";
    n = 11;
	ft_memmove(dest, src, n);
	memmove(dest2, src, n);
	if (memcmp(dest, dest2, n) != 0)
	{
		printf("ft_memmove_str 'Hello there': %s\n", dest);
		printf("memmove_str 'Hello there': %s\n", dest2);
		return ;
	}
	dest3 = (char *) ft_memmove(dest + 7, dest, n);
	dest4 = (char *) memmove(dest2 + 7, dest2, n);
	if (memcmp(dest3, dest4, 7) != 0)
	{
		printf("ft_memmove_str_over 'Hello there': %s\n", dest3);
		printf("memmove_str_over 'Hello there': %s\n", dest4);
		return ;
	}
    n = 5;
    ft_memmove(arr, arr2, n * sizeof(int));
    memmove(arr3, arr2, n * sizeof(int));
	if (memcmp(arr, arr3, n) != 0)
	{
		i = 0;
		printf("ft_memmove_arr '88 5 3 6 5': ");
		while (i < n)
		{
			printf("%d ", arr[i]);
			i++;
		}
		i = 0;
		printf("\nmemmove_arr '88 5 3 6 5': ");
		while (i < n)
		{
			printf("%d ", arr3[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	printf("ft_memmove: OK!\n");
}