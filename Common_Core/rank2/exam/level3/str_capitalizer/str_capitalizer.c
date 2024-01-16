#include <unistd.h>

int	check_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	check_cap(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	capit_str(char *str)
{
	int	first;

	while (*str != 0)
	{
		first = 0;
		while ((*str == ' ' || *str == '\t') && *str != 0)
		{
			write(1, str, 1);
			str++;
		}
		while (*str != ' ' && *str != '\t' && *str != 0)
		{
			if (check_cap(*str) == 0 && check_alpha(*str) == 1 && first == 0)
			{
				*str -= 32;
				write(1, str, 1);
				first++;
			}
			else if (check_cap(*str) == 1 && first != 0)
			{
				*str += 32;
				write(1, str, 1);
			}
			else
			{
				write(1, str, 1);
				first++;
			}
			str++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		capit_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
