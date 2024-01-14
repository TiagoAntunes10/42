#include <stdlib.h>
#include <unistd.h>

int long	ft_atoi(char *nbr)
{
	int long	num;

	if (*nbr < '0' || *nbr > '9')
		return (-1);
	num = 0;
	while (*nbr != 0)
	{
		if (*nbr < '0' || *nbr > '9')
			return (-1);
		num = num * 10 + *nbr - '0';
		nbr++;
	}
	return (num);
}

int	ft_sqrt(int num)
{
	int	i;

	if (num % 2 == 0)
	{
		i = 2;
		while (i * i < num)
			i += 2;
	}
	else
	{
		i = 1;
		while (i * i < num)
			i += 2;
	}
	return (i);
}

int	ft_isprime(int num)
{
	int	i;
	int	sq;

	i = 2;
	sq = ft_sqrt(num);
	if (num == 2 || num == 3)
		return (1);
	while (i <= sq)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_itoa(int sum)
{
	int		charac;
	char	c;

	if (sum / 10 == 0)
	{
		charac = sum % 10 + '0';
		c = charac;
		write(1, &c, 1);
		return ;
	}
	ft_itoa(sum / 10);
	charac = sum % 10 + '0';
	c = charac;
	write(1, &c, 1);
}

void	write_prime(int num)
{
	int		i;
	int		sum;

	i = 2;
	sum = 0;
	while (i <= num)
	{
		if (ft_isprime(i) == 1)
			sum += i;
		i++;
	}
	ft_itoa(sum);
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	num = atoi(argv[1]);
	if (num < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	write_prime(num);
}
