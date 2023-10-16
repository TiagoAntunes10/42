#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *str, ... )
{
	int		arg;
	va_list	valst;

	//arg = count_args(str);
	va_start(valst, arg);
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			write(1, "%", 1);
			str++;
		}
		else if (*str == '%')
			//write_spe(str, valst);
		else
			write(1, str, 1);
		str++;
	}
}