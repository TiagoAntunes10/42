#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_memchr(void)
{
    char    *s;
	char	*sub;
	char	*sub2;
    char    c;
	int		i;
	int		n;
	int		arr[4] = {4, 6, 7, 1};
	int		*arr2;
	int		*arr3;

    s = "hfdb hnjnhdfb";
    c = 'n';
	sub = (char *) ft_memchr(s, c, 10);
	sub2 = (char *) memchr(s, c, 10);
	i = 0;
	while (sub[i] != '\0' || sub2[i] != '\0')
	{
		if (sub[i] != sub2[i])
		{
			printf("ft_memchr_str 'njnhdfb': %s\n", sub);
			printf("memchr_str 'njnhdfb': %s\n",  sub2);
			return ;
		}
		i++;
	}
	sub = (char *) ft_memchr(s, c, 3);
	sub2 = (char *) memchr(s, c, 3);
	if (sub != sub2)
	{
		printf("ft_memchr_str 'NULL': %s\n", sub);
		printf("memchr_str 'NULL': %s\n",  sub2);
		return ;
	}
	n = 7;
	arr2 = (int *) ft_memchr(arr, i, 4 * sizeof(int));
	arr3 = (int *) memchr(arr, i, 4 * sizeof(int));
	n = 2;
	i = 0;
	while (i < n)
	{
		if (arr2[i] != arr3[i])
		{
			i = 0;
			printf("ft_memchr_arr '7 1': ");
			while (i < n)
			{
				printf("%d ", arr2[i]);
				i++;
			}
			printf("\nmemchr_arr '7 1': ");
			i = 0;
			while (i < n)
			{
				printf("%d ", arr3[i]);
				i++;
			}
			printf("\n");
			return ;
		}
		i++;
	}
	printf("ft_memchr: OK!\n");
}