#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			c;
	char			*str;
	int				nb;
	unsigned int	nb2;
	int				len;
	int				len2;

	c = 'a';
	str = "Hello there";
	nb = 56;
	nb2 = 56;
	len = ft_printf("NICE! %-3c\n%-5s\n%-4p\n%-4d\n%-4i\n%-4u\n%-4x\n%-4X\n%%\nNICE!\n", c, str, str, nb, nb, nb2, nb, nb);
	len2 = printf("NICE! %-3c\n%-5s\n%-4p\n%-4d\n%-4i\n%-4u\n%-4x\n%-4X\n%%\nNICE!\n", c, str, str, nb, nb, nb2, nb, nb);
	ft_printf("length: %d\nlength2: %d\n", len, len2);
}