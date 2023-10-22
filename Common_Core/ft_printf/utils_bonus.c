#include "libft.h"

void	write_char(unsigned int size, char c)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

int	write_left_str(char *str, unsigned int size)
{
		ft_putstr_fd(str, 1);
		if (size <= ft_strlen(str))
			return (ft_strlen(str));
		else
		{
			write_char(size - ft_strlen(str), ' ');
			return (size);
		}
}

int	write_precision_str(char *str, unsigned int size)
{
	if (size <= ft_strlen(str))
	{
		str = ft_substr(str, 0, size);
		ft_putstr_fd(str, 1);
		free(str);
		return (size);
	}
	else
	{
		write_char(size - ft_strlen(str), ' ');
		return (size);
	}
}