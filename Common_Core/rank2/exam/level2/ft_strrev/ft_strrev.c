char	*ft_strrev(char *str)
{
	int		begin;
	int		end;
	int		size;
	char	tmp;

	end = 0;
	while (str[end] != 0)
		end++;
	size = end;
	end--;
	while (begin < size / 2)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		end--;
		begin++;
	}
	return (str);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;
	int		size;
	int		i;

	size = 7;
	str = malloc(size);
	i = 0;
	while (i < size)
	{
		str[i] = 'a' + i;
		i++;
	}
	printf("%s\n", ft_strrev(str));
}
