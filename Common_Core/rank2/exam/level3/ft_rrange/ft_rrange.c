#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*array;
	int	size;
	int	i;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	array = malloc(sizeof(int) * (size));
	i = 0;
	if (start > end)
	{
		while (end <= start)
		{
			array[i] = end;
			end++;
			i++;
		}
	}
	else
	{
		while (end >= start)
		{
			array[i] = end;
			end--;
			i++;
		}
	}
	return (array);
}

#include <stdio.h>

int	main(void)
{
	int	*array;
	int	i;
	int	start;
	int	end;

	start = 0;
	end = -3;
	array = ft_rrange(start, end);
	i = 0;
	if (start > end)
	{
		while (i < (start - end + 1))
		{
			printf("%d\n", array[i]);
			i++;
		}
		free(array);
		return (0);
	}
	while (i < (end - start + 1))
	{
		printf("%d\n", array[i]);
		i++;
	}
	free(array);
}
