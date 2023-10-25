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
	//Character Tests
	ft_printf("Character Tests\n");
	ft_printf("1)");
	len = ft_printf("%c\n", c);
	len2 = printf("%c\n", c);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-5c\n", c);
	len2 = printf("%-5c\n", c);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	//String Tests
	ft_printf("String Tests\n");
	ft_printf("1)");
	len = ft_printf("%s\n", str);
	len2 = printf("%s\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-5s\n", str);
	len2 = printf("%-5s\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("3)");
	len = ft_printf("%-20s\n", str);
	len2 = printf("%-20s\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("4)");
	len = ft_printf("%.5s\n", str);
	len2 = printf("%.5s\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("5)");
	len = ft_printf("%.20s\n", str);
	len2 = printf("%.20s\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	//Pointer Tests
	ft_printf("Pointer Tests\n");
	ft_printf("1)");
	len = ft_printf("%p\n", str);
	len2 = printf("%p\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-5p\n", str);
	len2 = printf("%-5p\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("3)");
	len = ft_printf("%-20p\n", str);
	len2 = printf("%-20p\n", str);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	//Digit Tests
	ft_printf("Digit Tests\n");
	ft_printf("1)");
	len = ft_printf("%d\n", nb);
	len2 = printf("%d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-1d\n", nb);
	len2 = printf("%-1d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("3)");
	len = ft_printf("%-5d\n", nb);
	len2 = printf("%-5d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("4)");
	len = ft_printf("%+d\n", nb);
	len2 = printf("%+d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("5)");
	len = ft_printf("%+-2d\n", nb);
	len2 = printf("%+-2d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("6)");
	len = ft_printf("%+-5d\n", nb);
	len2 = printf("%+-5d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("7)");
	len = ft_printf("% -2d\n", nb);
	len2 = printf("% -2d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("8)");
	len = ft_printf("%02d\n", nb);
	len2 = printf("%02d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("9)");
	len = ft_printf("%+02d\n", nb);
	len2 = printf("%+02d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("10)");
	len = ft_printf("%.2d\n", nb);
	len2 = printf("%.2d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("11)");
	len = ft_printf("%.5d\n", nb);
	len2 = printf("%.5d\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	//Integer Tests
	ft_printf("Integer Tests\n");
	ft_printf("1)");
	len = ft_printf("%i\n", nb);
	len2 = printf("%i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-1i\n", nb);
	len2 = printf("%-1i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("3)");
	len = ft_printf("%-5i\n", nb);
	len2 = printf("%-5i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("4)");
	len = ft_printf("%+i\n", nb);
	len2 = printf("%+i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("5)");
	len = ft_printf("%+-2i\n", nb);
	len2 = printf("%+-2i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("6)");
	len = ft_printf("%+-5i\n", nb);
	len2 = printf("%+-5i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("7)");
	len = ft_printf("% -2i\n", nb);
	len2 = printf("% -2i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("8)");
	len = ft_printf("%02i\n", nb);
	len2 = printf("%02i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("9)");
	len = ft_printf("%+02i\n", nb);
	len2 = printf("%+02i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("10)");
	len = ft_printf("%.2i\n", nb);
	len2 = printf("%.2i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("11)");
	len = ft_printf("%.5i\n", nb);
	len2 = printf("%.5i\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	//Unsigned Int Tests
	ft_printf("Unsigned Integer Tests\n");
	ft_printf("1)");
	len = ft_printf("%u\n", nb2);
	len2 = printf("%u\n", nb2);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-1u\n", nb2);
	len2 = printf("%-1u\n", nb2);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("3)");
	len = ft_printf("%-5u\n", nb2);
	len2 = printf("%-5u\n", nb2);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("4)");
	len = ft_printf("%01u\n", nb2);
	len2 = printf("%01u\n", nb2);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("5)");
	len = ft_printf("%05u\n", nb2);
	len2 = printf("%05u\n", nb2);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("6)");
	len = ft_printf("%.1u\n", nb2);
	len2 = printf("%.1u\n", nb2);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("7)");
	len = ft_printf("%.5u\n", nb2);
	len2 = printf("%.5u\n", nb2);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	//Hexadecimal Lower Case Tests
	ft_printf("Hexadecimal Lower Case Tests\n");
	ft_printf("1)");
	len = ft_printf("%x\n", nb);
	len2 = printf("%x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-1x\n", nb);
	len2 = printf("%-1x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("3)");
	len = ft_printf("%-6x\n", nb);
	len2 = printf("%-6x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("4)");
	len = ft_printf("%#-3x\n", nb);
	len2 = printf("%#-3x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("5)");
	len = ft_printf("%01x\n", nb);
	len2 = printf("%01x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("6)");
	len = ft_printf("%06x\n", nb);
	len2 = printf("%06x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("7)");
	len = ft_printf("%#06x\n", nb);
	len2 = printf("%#06x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	
	ft_printf("8)");
	len = ft_printf("%.1x\n", nb);
	len2 = printf("%.1x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("9)");
	len = ft_printf("%.6x\n", nb);
	len2 = printf("%.6x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("10)");
	len = ft_printf("%#.6x\n", nb);
	len2 = printf("%#.6x\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	//Hexadecimal Upper Case Tests
	ft_printf("Hexadecimal Upper Case Tests\n");
	ft_printf("1)");
	len = ft_printf("%X\n", nb);
	len2 = printf("%X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("2)");
	len = ft_printf("%-1X\n", nb);
	len2 = printf("%-1X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("3)");
	len = ft_printf("%-6X\n", nb);
	len2 = printf("%-6X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("4)");
	len = ft_printf("%#-3X\n", nb);
	len2 = printf("%#-3X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("5)");
	len = ft_printf("%01X\n", nb);
	len2 = printf("%01X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("6)");
	len = ft_printf("%06X\n", nb);
	len2 = printf("%06X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("7)");
	len = ft_printf("%#06X\n", nb);
	len2 = printf("%#06X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	
	ft_printf("8)");
	len = ft_printf("%.1X\n", nb);
	len2 = printf("%.1X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("9)");
	len = ft_printf("%.6X\n", nb);
	len2 = printf("%.6X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("10)");
	len = ft_printf("%#.6X\n", nb);
	len2 = printf("%#.6X\n", nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);

	ft_printf("Everything together\n");
	len = ft_printf("%-3c\n%-5s\n%-4p\n%-4d\n%-4i\n%-4u\n%-4x\n%-4X\n%%\n\n", c, str, str, nb, nb, nb2, nb, nb);
	len2 = printf("%-3c\n%-5s\n%-4p\n%-4d\n%-4i\n%-4u\n%-4x\n%-4X\n%%\n\n", c, str, str, nb, nb, nb2, nb, nb);
	ft_printf("length: %d\nlength2: %d\n\n", len, len2);
}