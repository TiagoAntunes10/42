#include <stdlib.h>
#include <unistd.h>

int	ft_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	(void) argc;
	while(*(argv[1]) != 0)
	{
		while (*(argv[1]) == '_')
			argv[1]++;
		while (*(argv[1]) != '_' && *(argv[1]) != 0)
		{
			if (ft_isalpha(*(argv[1])) == 1 && *(argv[1] - 1) == '_')
			{
				*(argv[1]) -= 32;
				write(1, argv[1], 1);
			}
			else
				write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
}