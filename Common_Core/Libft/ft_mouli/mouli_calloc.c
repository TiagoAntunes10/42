#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	mouli_calloc(void)
{
	char	*src;
	char	*dest;
	char	*dest2;
    int 	*arr;
    int 	*arr2;
    int 	nmem;
    int 	size;
    int 	i;

    nmem = 5;
	size = sizeof(char);
	src = "Olas";
	dest = ft_calloc(nmem, size);
	dest2 = calloc(nmem, size);
	ft_strlcpy(dest, src, nmem);
	ft_strlcpy(dest2, src, nmem);
	i = 0;
	while (dest[i] != '\0' || dest2[i] != '\0')
	{
		if (dest[i] != dest2[i])
		{
			printf("ft_calloc_str: %s\n", dest);
			printf("calloc_str: %s\n", dest2);
		}
		i++;
	}
	free(dest);
	free(dest2);
    size = sizeof(int);
    arr = ft_calloc(nmem, size);
    arr2 = calloc(nmem, size);
    i = 0;
    while (i < nmem)
    {
        arr[i] = i + 3;
        arr2[i] = i + 3;
        i++;
    }
    i = 0;
	while (i < nmem)
	{
		if (arr[i] != arr2[i])
		{
			printf("ft_calloc_arr: ");
			while (i < nmem)
			{
				printf("%d ", arr[i]);
				i++;
			}
			printf("\n");
			i = 0;
			printf("calloc_arr: ");
			while (i < nmem)
			{
				printf("%d ", arr2[i]);
				i++;
			}
			printf("\n");
			free(arr);
			free(arr2);
		}
		i++;
	}
	free(arr);
	free(arr2);
	printf("ft_calloc: OK!\n");
}