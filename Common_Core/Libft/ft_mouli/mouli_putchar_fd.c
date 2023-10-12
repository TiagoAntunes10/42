#include "libft.h"
#include <unistd.h>

void	mouli_putchar_fd(void)
{
	write(1, "ft_putchar_fd 'g': ", 19);
	ft_putchar_fd('g', 1);
	write(1, "\n", 1);
}