#include <unistd.h>

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str != 0)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str != 0)
			count++;
		while(*str != ' ' && *str != '\t' && *str != 0)
			str++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	words;
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	words = count_words(argv[1]);
	if (words == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (*(argv[1]) != 0)
	{
		while (*(argv[1]) == ' ' || *(argv[1]) == '\t')
			argv[1]++;
		i++;
		while(*(argv[1]) != ' ' && *(argv[1]) != '\t' && *(argv[1]) != 0)
		{
			if (i == words)
				write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
}
