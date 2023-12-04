#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_memcmp(void)
{
    char    *s1;
    char    *s2;
	char	*s3;
    int     arr1[5] = {1, 2, 3, 4, 5};
    int     arr2[5] = {1, 2, 3, 4, 5};
	int     arr3[5] = {1, 1, 2, 3, 3};
	unsigned int	n;
	unsigned int	i;

	n = 8;
    s1 = "hello world";
    s2 = "hello world";
	s3 = "hello World";
	if (ft_memcmp(s1, s2, n) != memcmp(s1, s2, n))
	{
		printf("ft_memcmp_str '0': %d\n", ft_memcmp(s1, s2, n));
		printf("memcmp_str '0': %d\n", memcmp(s1, s2, n));
		return ;
	}
	if (ft_memcmp(s1, s3, n) != memcmp(s1, s3, n))
	{
		printf("ft_memcmp_str '32': %d\n", ft_memcmp(s1, s3, n));
		printf("memcmp_str '32': %d\n", memcmp(s1, s3, n));
		return ;
	}
	i = 4 * sizeof(int);
	if (ft_memcmp(arr1, arr2, i) != memcmp(arr1, arr2, i))
	{
		printf("ft_memcmp_arr '0': %d\n", ft_memcmp(arr1, arr2, i));
		printf("memcmp_arr '0': %d\n", memcmp(arr1, arr2, i));
		return ;
	}
	if (ft_memcmp(arr1, arr3, i) != memcmp(arr1, arr3, i))
	{
		printf("ft_memcmp_arr '1': %d\n", ft_memcmp(arr1, arr3, i));
		printf("memcmp_arr '1': %d\n", memcmp(arr1, arr3, i));
		return ;
	}
	printf("ft_memcmp: OK!\n");
}