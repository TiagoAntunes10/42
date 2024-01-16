#include <unistd.h>

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str != 0)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

void	ft_itoa_base(int num)
{
	char	c;

	if ((num / 16) == 0)
	{
		c = "0123456789abcdef"[num % 16];
		write(1, &c, 1);
		return ;
	}
	ft_itoa_base(num / 16);
	c = "0123456789abcdef"[num % 16];
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	num = ft_atoi(argv[1]);
	ft_itoa_base(num);
	write(1, "\n", 1);
}
