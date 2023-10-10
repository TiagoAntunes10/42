#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	mouli_atoi(void)
{
	char	*str;

	str = "-2147483648";
	if (ft_atoi(str) != atoi(str))
	{
		printf("ft_atoi '-2147483648': %d\n", ft_atoi(str));
		printf("atoi '-2147483648': %d\n", atoi(str));
		return ;
	}
	str = "2147483647";
	if (ft_atoi(str) != atoi(str))
	{
		printf("ft_atoi '2147483647': %d\n", ft_atoi(str));
		printf("atoi '2147483647': %d\n", atoi(str));
		return ;
	}
	str = "3455 g463";
	if (ft_atoi(str) != atoi(str))
	{
		printf("ft_atoi '3455fg463: %d\n", ft_atoi(str));
		printf("atoi '3455fg463: %d\n", atoi(str));
		return ;
	}
	str = " \n\t\r\v\f-6436";
	if (ft_atoi(str) != atoi(str))
	{
		printf("ft_atoi '  \\n\\t\\r\\v\\f-6436': %d\n", ft_atoi(str));
		printf("atoi ' \\n\\t\\r\\v\\f-6436': %d\n", atoi(str));
		return ;
	}
	str = "--654";
	if (ft_atoi(str) != atoi(str))
	{
		printf("ft_atoi '--654': %d\n", ft_atoi(str));
		printf("atoi '--654': %d\n", atoi(str));
		return ;
	}
	str = "\a74567";
	if (ft_atoi(str) != atoi(str))
	{
		printf("ft_atoi '\\a74567': %d\n", ft_atoi(str));
		printf("atoi '\\a74567': %d\n", atoi(str));
		return ;
	}
	str = "\b465";
	if (ft_atoi(str) != atoi(str))
	{
		printf("ft_atoi '\\b465': %d\n", ft_atoi(str));
		printf("atoi '\\b465': %d\n", atoi(str));
		return ;
	}
	printf("ft_atoi: OK!\n");
}