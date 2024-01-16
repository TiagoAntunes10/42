#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*(argv[2]) != 0)
	{
		if (*(argv[1]) == 0)
		{
			write(1, "1\n", 2);
			return (0);
		}
		else if(*(argv[1]) == *(argv[2]))
			argv[1]++;
		argv[2]++;
	}
	write(1, "0\n", 2);
}
