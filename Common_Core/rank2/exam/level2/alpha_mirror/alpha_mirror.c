#include <unistd.h>

int	ft_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*(argv[1]) != 0)
	{
		if (ft_alpha(*(argv[1])) == 1)
		{
			*(argv[1]) = 'z' - (*(argv[1]) - 'a');
			write(1, argv[1], 1);
		}
		else if (ft_alpha(*(argv[1])) == 2)
		{
			*(argv[1]) = 'Z' - (*(argv[1]) - 'A');
			write(1, argv[1], 1);
		}
		else
			write(1, argv[1], 1);
		argv[1]++;
	}
	write(1, "\n", 1);
}
