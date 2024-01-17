int	is_power_of_2(unsigned int n)
{
	while (n / 2 > 1 && n % 2 == 0)
		n /= 2;
	if (n / 2 == 1)
		return (1);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	unsigned int	n;

	n = 60;
	printf("%d\n", is_power_of_2(n));
}