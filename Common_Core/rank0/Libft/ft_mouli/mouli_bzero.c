#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_bzero(void)
{
	char            str[] = "fhbfdh dhfhbhoasj nhahb";
    char            str2[] = "fhbfdh dhfhbhoasj nhahb";
    unsigned int    n;
    int             arr[7];
    int             arr2[7];
    unsigned int    i;

    n = 7;
    ft_bzero(str + 12, n);
    bzero(str2 + 12, n);
	i = 0;
	while (str[i] != '\0' || str2[i] != '\0')
	{
		if (str[i] != str2[i])
		{
    		printf("ft_bzero 'fhbfdh dhfhbhoasj nhahb': %s\n", str);
    		printf("bzero 'fhbfdh dhfhbhoasj nhahb': %s\n", str2);
			return ;
		}
		i++;
	}
	ft_bzero(str + 6, n);
    bzero(str2 + 6, n);
	i = 0;
	while (str[i] != '\0' || str2[i] != '\0')
	{
		if (str[i] != str2[i])
		{
    		printf("ft_bzero 'fhbfdh dhfhbhoasj nhahb': %s\n", str);
    		printf("bzero 'fhbfdh dhfhbhoasj nhahb': %s\n", str2);
			return ;
		}
		i++;
	}
    ft_bzero(arr, n * sizeof(int));
    bzero(arr2, n * sizeof(int));
    i = 0;
	while (i < n)
	{
		if (arr[i] != arr2[i])
		{
			i = 0;
			printf("ft_bzero_arr: ");
			while (i < n)
			{
				printf("%d ", arr[i]);
				i++;
			}
			printf("\nbzero_arr: ");
			i = 0;
			while (i < n)
			{
				printf("%d ", arr2[i]);
				i++;
			}
			printf("\n");
			return ;
		}
		i++;
	}
	printf("ft_bzero: OK!\n");
}
