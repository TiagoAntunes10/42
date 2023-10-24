#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

static char	*format_str(const char *str);

int	write_bonus(const char *str, va_list valst, int count)
{
	char	*format;

	format = format_str(str);
	if (format[ft_strlen(format) - 1] == 'c')
		return (write_c(valst, count, format));
	else if (format[ft_strlen(format) - 1] == 's')
		return (write_s(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'p')
		return (write_p(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'd')
		return (write_d(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'i')
		return (write_i(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'u')
		return (write_u(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'x')
		return (write_x_lower(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'X')
		return (write_x_upper(valst, count, format) - 1);
	else
		return (-1);
}

static char	*format_str(const char *str)
{
	unsigned int	i;

	i = 0;
	while (ft_isalpha(str[i]) == 0)
		i++;
	return (ft_substr(str, 0, i + 1));
}
