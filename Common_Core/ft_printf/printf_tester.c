#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	len;
	int	len2;


	len = ft_printf("%50.2s", NULL);
	ft_printf("\n");
	len2 = printf("%50.2s", NULL);
	ft_printf("ft: %d\nprintf: %d\n", len, len2);
}