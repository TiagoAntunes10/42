int	max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	max = 0;
	i = 0;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

#include <stdio.h>

int	main(void)
{
	int	tab[6] = {100, 2, 3, 4, 5, 6};

	printf("%d\n", max(tab, 6));
}