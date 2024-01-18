#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	back;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != 0)
	{
		back = 0;
		while (argv[2][back] != 0)
		{
			if (argv[2][back] == argv[1][i])
				break ;
			back++;
		}
		if (argv[2][back] != 0)
		{
			back = i - 1;
			while (back >= 0)
			{
				if (argv[1][i] == argv[1][back])
					break ;
				back--;
			}
			if (back == -1)
				write(1, &(argv[1][i]), 1);
		}
		i++;
	}
	write(1, "\n", 1);
}
