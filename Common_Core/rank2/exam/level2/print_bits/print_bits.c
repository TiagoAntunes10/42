#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned int	i;

	i = 1 << 7;
	while (i > 0)
	{
		if ((octet & i) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i /= 2;
	}
}

int	main(void)
{
	unsigned char	octet;

	octet = 255;
	print_bits(octet);
}
