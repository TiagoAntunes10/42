#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *len)
{
	if (str == NULL)
		str = "(null)";
	while (*str != 0)
		*len += write(1, str++, 1);
}

void	put_nb(long long int nb, int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if (nb >= base)
		put_nb(nb / base, base, len);
	*len += write(1, &hexa[nb % base], 1);
}

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, format);
	len = 0;
	while (*format != 0)
	{
		if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(arg, char *), &len);
			else if (*format == 'd')
				put_nb((long long int) va_arg(arg, int), 10, &len);
			else if (*format == 'x')
				put_nb((long long int) va_arg(arg, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (len);
}

int	main(void)
{
	ft_printf("%d\n", ft_printf("%s\n", "toto"));
	ft_printf("%d\n", ft_printf("The magic %s is %d\n", "number", -42));
	ft_printf("%d\n", ft_printf("%d in hexadecimal is %x\n", 42, 42));
}
