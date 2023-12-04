#include <stdio.h>
#include "libft.h"

void	mouli_strnstr(void)
{
    char    		*s1;
    char    		*s2;
	char			*s3;
	unsigned int	n;

	n = 7;
    s1 = "teteste";
    s2 = "teste";
	s3 = ft_strnstr(s1, s2, n);
	if (ft_strncmp(s3, s2, 5) != 0)
	{
		printf("ft_strnstr 'teste': %s\n", s3);
		printf("Check 'teste': %s\n", s2);
		return ;
	}
	s1 = "teteste";
    s2 = "knbv";
	s3 = ft_strnstr(s1, s2, n);
	if (s3 != NULL)
	{
		printf("ft_strnstr 'NULL': %s\n", s3);
		printf("Check 'NULL': %s\n", s2);
		return ;
	}
	s1 = "teteste";
    s2 = "\0";
	s3 = ft_strnstr(s1, s2, n);
	if (ft_strncmp(s1, s3, n) != 0)
	{
		printf("ft_strnstr_str 'teteste': %s\n", s3);
		printf("Check 'teteste': %s\n", s1);
		return ;
	}
	printf("ft_strnstr: OK!\n");
}