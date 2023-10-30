#include "libft.h"
#include "ft_printf.h"

int	write_space_base_X(int long nb, unsigned int size, int count,
					long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_base_X(nb, size_precision, count));
	else if (size_precision == -1)
	{
		if (size <= (unsigned int)(base_len(nb) + count))
		{
			ft_putnbr_base(nb, "0123456789ABCDEF");
			return (base_len(nb) + count);
		}
		else
		{
			write_char(size - (base_len(nb) + count), ' ');
			ft_putnbr_base(nb, "0123456789ABCDEF");
			return (size);
		}
	}
	else
	{
		if (nb < 0)
			write_char(size - (size_precision + count + 1), ' ');
		else
			write_char(size - (size_precision + count), ' ');
		write_precision_base_X(nb, size_precision, count);
		return (size);
	}
}

int	write_left_base_X(unsigned long int nb, unsigned int size,
						int count, long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_base_X(nb, size_precision, count));
	else if (size_precision == -1)
	{
		ft_putnbr_base(nb, "0123456789ABCDEF");
		if (size <= (base_len(nb) + count))
			return ((base_len(nb) + count));
		else
		{
			write_char(size - (base_len(nb) + count), ' ');
			return (size);
		}
	}
	else
	{
		count = write_precision_base_X(nb, size_precision, count);
		write_char(size - count, ' ');
		return (size);
	}
}

int	write_precision_base_X(unsigned long int nb, unsigned int size,
							int count)
{
	if (size == 0 && nb == 0)
		return (count);
	else if (size <= (base_len(nb) + count))
	{
		ft_putnbr_base(nb, "0123456789ABCDEF");
		return ((base_len(nb) + count));
	}
	else
	{
		write_char(size - (base_len(nb)), '0');
		ft_putnbr_base(nb, "0123456789ABCDEF");
		return (size + count);
	}
}

int	write_zero_base_X(unsigned long int nb, unsigned int size,
						int count, long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_base_X(nb, size_precision, count));
	else if (size_precision == -1)
	{
		if (size <= (base_len(nb) + count))
		{
			ft_putnbr_base(nb, "0123456789ABCDEF");
			return ((base_len(nb) + count));
		}
		else
		{
			write_char(size - (base_len(nb) + count), '0');
			ft_putnbr_base(nb, "0123456789ABCDEF");
			return (size);
		}
	}
	else
		return (write_space_base_X(nb, size, count, size_precision));
}
