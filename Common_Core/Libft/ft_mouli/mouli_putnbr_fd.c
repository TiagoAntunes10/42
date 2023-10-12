#include "libft.h"
#include <unistd.h>

void	mouli_putnbr_fd(void)
{
	int	nb;

	nb = -2147483648;
	write(1, "ft_putnbr_fd '-2147483648': ", 28);
	ft_putnbr_fd(nb, 1);
	write(1, "\n", 1);
}