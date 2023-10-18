#include "libftprintf.h"

int	main(void)
{
	char	c;
	char	*str;
	int		nb;
	double	nb2;

	c = 'a';
	str = "Hello there";
	nb = 56;
	nb2 = 34.546;
	ft_printf("%c\n", c);
	ft_printf("%s\n", str);
	ft_printf("%i\n", nb);
	ft_printf("%d\n", nb2);
}