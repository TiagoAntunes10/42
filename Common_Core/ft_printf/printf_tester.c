#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	len;
	int	len2;


	len = ft_printf("%8.3i", -8473);
	ft_printf("\n");
	len2 = printf("%8.3i", -8473);
	ft_printf("ft: %d\nprintf: %d\n", len, len2);
}