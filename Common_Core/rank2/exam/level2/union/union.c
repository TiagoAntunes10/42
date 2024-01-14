#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != 0)
	{
		j = i - 1;
		if (i == 0)
			write(1, &(argv[1][i]), 1);
		else
		{
			while (j >= 0)
			{
				if (argv[1][i] == argv[1][j])
					break ;
				j--;
			}
			if (argv[1][j] == 0)
				write(1, &(argv[1][i]), 1);
		}
		i++;
	}
	i = 0;
	while (argv[2][i] != 0)
	{
		j = 0;
		while (argv[1][j] != 0)
		{
			if (argv[2][i] == argv[1][j])
				break ;
			j++;
		}
		if (argv[1][j] == 0)
		{
			j = i - 1;
			if (i == 0)
				write(1, &(argv[2][i]), 1);
			else
			{
				while (j >= 0)
				{
					if (argv[2][i] == argv[2][j])
						break ;
					j--;
				}
				if (argv[2][j] == 0)
					write(1, &(argv[2][i]), 1);
			}
		}
		i++;
	}
}
