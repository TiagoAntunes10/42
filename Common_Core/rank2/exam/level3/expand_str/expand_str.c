#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (*(argv[1]) != 0)
	{
		while (*(argv[1]) == ' ' || *(argv[1]) == '\t')
			argv[1]++;
		while (*(argv[1]) != ' ' && *(argv[1]) != '\t' && *(argv[1]) != 0)
		{
			if ((*(argv[1] - 1) == ' ' || *(argv[1] - 1) == '\t') && i != 0)
				write(1, "   ", 3);
			write(1, argv[1], 1);
			i++;
			argv[1]++;
		}
	}
}
