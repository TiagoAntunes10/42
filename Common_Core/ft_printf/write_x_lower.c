/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:27:00 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:27:01 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	write_base_bonus(unsigned int nb, int count, char *format);

int	write_x_lower(va_list valst, int count, char *format)
{
	unsigned int	nb;

	nb = va_arg(valst, unsigned int);
	if (*format == '-' || *format == '.' || *format == '0')
		return (count + write_base_bonus(nb, 0, format));
	else if (*format == '#')
	{
		ft_putstr_fd("0x", 1);
		return (count + 2 + write_base_bonus(nb, 1, ++format));
	}
	else if (*format == 0)
	{
		count += ft_putnbr_base(nb, "0123456789abcdef");
		return (count);
	}
	return (-1);
}

static int	write_left_base(unsigned int nb, unsigned int size, int count)
{
	ft_putnbr_base(nb, "0123456789abcdef");
	if (size <= (base_len(nb) + count))
		return ((base_len(nb) + count));
	else
	{
		write_char(size - (base_len(nb) + count), ' ');
		return (size);
	}
}

static int	write_precision_base(unsigned int nb, unsigned int size, int count)
{
	if (size == 0 && nb == 0)
		return (count);
	else if (size <= (base_len(nb) + count))
	{
		ft_putnbr_base(nb, "0123456789abcdef");
		return ((base_len(nb) + count));
	}
	else
	{
		write_char(size - (base_len(nb) + count), '0');
		ft_putnbr_base(nb, "0123456789abcdef");
		return (size);
	}
}

static int	write_zero_base(unsigned int nb, unsigned int size, int count)
{
	if (size <= (base_len(nb) + count))
	{
		ft_putnbr_base(nb, "0123456789abcdef");
		return ((base_len(nb) + count));
	}
	else
	{
		write_char(size - (base_len(nb) + count), '0');
		ft_putnbr_base(nb, "0123456789abcdef");
		return (size);
	}
}

static int	write_base_bonus(unsigned int nb, int count, char *format)
{
	unsigned int	size;

	size = ft_atoi(format + 1);
	if (*format == '-')
	{
		free(format);
		return (count + write_left_base(nb, size, count));
	}
	else if (*format == '.')
	{
		free(format);
		return (count + write_precision_base(nb, size, count));
	}
	else if (*format == '0')
	{
		free(format);
		return (count + write_zero_base(nb, size, count));
	}
	return (-1);
}
