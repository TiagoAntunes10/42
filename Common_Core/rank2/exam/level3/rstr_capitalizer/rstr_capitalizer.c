#include <unistd.h>

int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isupp(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	check_c(char c)
{
	if (c == ' ' || c == '\t' || c == 0)
		return (1);
	return (0);
}

void	rcapital_write(char *str)
{
	while (*str != 0)
	{
		while (*str == ' ' || *str == '\t')
		{
			write(1, str, 1);
			str++;
		}
		while (*str != ' ' && *str != '\t' && *str != 0)
		{
			if (ft_isalpha(*str) == 1 && ft_isupp(*str) == 0 && check_c(*(str + 1)) == 1)
			{
				*str -= 32;
				write(1, str, 1);
			}
			else if (ft_isupp(*str) == 1 && check_c(*(str + 1)) == 0)
			{
				*str += 32;
				write(1, str, 1);
			}
			else
				write(1, str, 1);
			str++;
		}
	}
}
int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		write(1,"\n", 1);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		rcapital_write(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
