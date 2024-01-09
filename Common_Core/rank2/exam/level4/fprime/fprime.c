#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int num)
{
	int	sq;

	if (num % 2 == 0)
	{
		sq = 2;
		while (sq * sq < num)
			sq += 2;
		return (sq);
	}
	sq = 1;
	while (sq * sq < num)
		sq += 2;
	return (sq);
}

int	ft_isprime(int num)
{
	int	div;
	int	sq;

	sq = ft_sqrt(num);
	if (num == 2 || num == 3)
		return (0);
	div = 2;
	while (num % div != 0 && div < sq)
		div++;
	if (num % div == 0)
		return (1);
	return (0);
}

void	write_fprime(int num)
{
	int	div;

	if (num == 1)
	{
		printf("1\n");
		return ;
	}
	div = 2;
	while (num >= 1)
	{
		if (ft_isprime(div) == 0)
		{
			while (num % div == 0)
			{
				if (num % div == 0 && num / div == 1)
				{
					printf("%d\n", div);
					return ;
				}
				else if (num % div == 0)
				{
					printf("%d*", div);
					num /= div;
				}
			}
		}
		div++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	num = atoi(argv[1]);
	write_fprime(num);
}
