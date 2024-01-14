void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (size - 1 >= j)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	tab[7] = {6, 1, 93, 9, 8, 1, 16};
	int	i;

	i = 0;
	sort_int_tab(tab, 7);
	while (i < 7)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
