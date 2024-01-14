unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	i;
	unsigned char	octet_right;

	octet_right = octet;
	i = 7;
	octet >>= 1;
	while (octet != 0)
	{
		octet_right <<= 1;
		octet_right |= octet & 1;
		octet >>= 1;
		i--;
	}
	octet_right <<= i;
	return (octet_right);
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

	c = 1;
	printf("Before: ");
	bin(c);
	printf("\nAfter: ");
	bin(reverse_bits(c));
}
