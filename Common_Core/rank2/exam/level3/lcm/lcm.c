unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	i;
	int	j;

	if (a == 0 || b == 0)
		return (0);
	i = 1;
	j = 1;
	while (a * i != b * j)
	{
		while (a * i < b * j)
			i++;
		while (b * j < a * i)
			j++;
	}
	return (a * i);
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 4765;
	b = 83567;
	printf("a = %d\nb = %d\n", a, b);
	printf("lcm = %d\n", lcm(a, b));
}
