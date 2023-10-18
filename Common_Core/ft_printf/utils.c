#include <unistd.h>
#include "libft.h"
#include "libftprintf.h"

int	nb_len(int long nb)
{
	int	l;

	l = 0;
	if (nb < 0)
	{
		l = 1;
		nb *= -1;
	}
	if (nb / 10 == 0)
		return (1);
	l += 1;
	l += nb_len(nb / 10);
	return (l);
}

int	write_double(double nb, int dec, int size)
{
	int	i;

	nb *= ft_power(10, dec);
	i = 1;
	if ((int) nb / 10 == 0)
	{
		ft_putchar_fd(((int) nb % 10) + 48, 1);
		return (i);
	}
	i += write_double(nb / 10, 0, size);
	ft_putchar_fd(((int) nb % 10) + 48, 1);
	if (size == i)
		ft_putchar_fd('.', 1);
	return (i);
}

int	ft_power(int base, int exp)
{
	int	result;

	result = base;
	if (exp == 0)
		return (1);
	result *= ft_power(base, exp - 1);
	return (result);
}