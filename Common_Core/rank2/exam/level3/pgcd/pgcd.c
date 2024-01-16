#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int	num1;
	int	num2;
	int	div;
	int	i;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	i = 1;
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	if (num1 < num2)
	{
		while (i <= num1)
		{
			if (num1 % i == 0 && num2 % i == 0)
				div = i;
			i++;
		}
	}
	else
	{
		while (i <= num2)
		{
			if (num1 % i == 0 && num2 % i == 0)
				div = i;
			i++;
		}
	}
	printf("%d\n", div);
}
