#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

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

int	write_left_nb(int long nb, unsigned int size, int count)
{
	ft_putnbr_fd(nb, 1);
	if (size <= (unsigned int) (nb_len(nb) + count))
		return ((nb_len(nb) + count));
	else
	{
		write_char(size - (nb_len(nb) + count), ' ');
		return (size);
	}
}

int	write_precision_nb(int long nb, unsigned int size, int count)
{
	if (size == 0 && nb == 0)
		return (count);
	else if (size <= (unsigned int) (nb_len(nb) + count))
	{
		ft_putnbr_fd(nb, 1);
		return ((nb_len(nb) + count));
	}
	else
	{
		write_char(size - (nb_len(nb) + count), '0');
		ft_putnbr_fd(nb, 1);
		return (size);
	}
}

int	write_zero_nb(int long nb, unsigned int size, int count)
{
	if (size <= (unsigned int) (nb_len(nb) + count))
	{
		ft_putnbr_fd(nb, 1);
		return ((nb_len(nb) + count));
	}
	else
	{
		write_char(size - (nb_len(nb) + count), '0');
		ft_putnbr_fd(nb, 1);
		return (size);
	}
}

int	write_nb_bonus(int long nb, int count, char *format)
{
	unsigned int	size;

	size = ft_atoi(format + 1);
	if (*format == '-')
	{
		free(format);
		return (count + write_left_nb(nb, size, count));
	}
	else if (*format == '.')
	{
		free(format);
		return (count + write_precision_nb(nb, size, count));
	}
	else if (*format == '0')
	{
		free(format);
		return (count + write_zero_nb(nb, size, count));
	}
	else if (*format == 'i' || *format == 'd')
	{
		free(format);
		return (count + write_left_nb(nb, size, count));
	}
	return (-1);
}
