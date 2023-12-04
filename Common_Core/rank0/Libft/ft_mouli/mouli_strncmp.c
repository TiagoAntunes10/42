#include <string.h>
#include <stdio.h>
#include "libft.h"

void	mouli_strncmp(void)
{
    char    		*s1;
    char    		*s2;
	char			*s3;
	unsigned int	n;

	n = 8;
    s1 = "hello world";
    s2 = "hello world";
	s3 = "hello World";
	if (ft_strncmp(s1, s2, n) != strncmp(s1, s2, n))
	{
		printf("ft_strncmp_str '0': %d\n", ft_strncmp(s1, s2, n));
		printf("strncmp_str '0': %d\n", strncmp(s1, s2, n));
		return ;
	}
	if (ft_strncmp(s1, s3, n) != strncmp(s1, s3, n))
	{
		printf("ft_strncmp_str '32': %d\n", ft_strncmp(s1, s3, n));
		printf("strncmp_str '32': %d\n", strncmp(s1, s3, n));
		return ;
	}
	if (ft_strncmp(s3, s1, n) != strncmp(s3, s1, n))
	{
		printf("ft_strncmp_str '-32': %d\n", ft_strncmp(s3, s1, n));
		printf("strncmp_str '-32': %d\n", strncmp(s3, s1, n));
		return ;
	}
	printf("ft_strncmp: OK!\n");
}