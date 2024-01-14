unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	octet_mov;

	octet_mov = octet >> 4;
	octet = octet << 4;
	return (octet|octet_mov);
}

#include <stdio.h>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int	main(void)
{
	unsigned char	c;

	c = 5;
	printf("Before: ");
	bin(c);
	printf("\nAfter: ");
	bin(swap_bits(c));
}
