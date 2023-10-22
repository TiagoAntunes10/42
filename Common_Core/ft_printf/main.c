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
	//len = ft_printf("NICE! %c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\nNICE!\n", c, str, str, nb, nb, nb2, nb, nb);
	len2 = printf("%.10p", str);
	//ft_printf("length: %d\nlength2: %d\n", len, len2);
}