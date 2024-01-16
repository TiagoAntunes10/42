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

void	ft_itoa(int num)
{
	char	c;
	int		asc;

	if (num / 10 == 0)
	{
		asc = (num % 10) + '0';
		c = asc;
		write(1, &c, 1);
		return ;
	}
	ft_itoa(num / 10);
	asc = (num % 10) + '0';
	c = asc;
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != 0)
	{
		len++;
		str++;
	}
	return (len);
}

int	main(int argc, char **argv)
{
	int	input;
	int	i;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	input = ft_atoi(argv[1]);
	i = 1;
	while (i <= 9)
	{
		ft_itoa(i);
		write(1, " x ", 3);
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, " = ", 3);
		ft_itoa(i * input);
		write(1, "\n", 1);
		i++;
	}
}
