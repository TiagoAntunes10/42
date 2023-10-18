#include "libftprintf.h"

int	main(void)
{
	char	c;
	char	*str;
	int		nb;

	c = 'a';
	str = "Hello there";
	nb = 56;
	ft_printf("%c\n", c);
	ft_printf("%s\n", str);
	ft_printf("%i\n", nb);
}