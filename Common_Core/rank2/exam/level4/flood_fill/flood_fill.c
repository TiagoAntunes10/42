#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;
	int		i;
	int		j;

	c = tab[(&begin)->y][(&begin)->x];
	i = 0;
	while (i < (&size)->y)
	{
		j = 0;
		while (j < (&size)->x)
		{
			if (tab[i][j] == c)
				tab[i][j] = 'F';
			j++;
		}
		i++;
	}
}
