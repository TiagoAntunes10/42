/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x_X_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:48:28 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/26 16:48:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	write_left_base(unsigned long int nb, unsigned int size,
		int count, char *base)
{
	ft_putnbr_base(nb, base);
	if (size <= (base_len(nb) + count))
		return ((base_len(nb) + count));
	else
	{
		write_char(size - (base_len(nb) + count), ' ');
		return (size);
	}
}

static int	write_precision_base(unsigned long int nb, unsigned int size,
							int count, char *base)
{
	if (size == 0 && nb == 0)
		return (count);
	else if (size <= (base_len(nb) + count))
	{
		ft_putnbr_base(nb, base);
		return ((base_len(nb) + count));
	}
	else
	{
		write_char(size - (base_len(nb)), '0');
		ft_putnbr_base(nb, base);
		return (size + count);
	}
}

static int	write_zero_base(unsigned long int nb, unsigned int size,
						int count, char *base)
{
	if (size <= (base_len(nb) + count))
	{
		ft_putnbr_base(nb, base);
		return ((base_len(nb) + count));
	}
	else
	{
		write_char(size - (base_len(nb) + count), '0');
		ft_putnbr_base(nb, base);
		return (size);
	}
}

int	write_base_bonus(unsigned long int nb, int count, char *format, char *base)
{
	unsigned int	size;

	size = ft_atoi(format + 1);
	if (*format == '-')
	{
		free(format);
		return (write_left_base(nb, size, count, base));
	}
	else if (*format == '.')
	{
		free(format);
		return (write_precision_base(nb, size, count, base));
	}
	else if (*format == '0')
	{
		free(format);
		return (write_zero_base(nb, size, count, base));
	}
	return (-1);
}

int	write_base_extra_bonus(unsigned long int nb, int count, char *format, char *base)
{
	unsigned int	size;

	size = ft_atoi(format + 1);
	if (*format == '-')
	{
		free(--format);
		return (write_left_base(nb, size, count, base));
	}
	else if (*format == '.')
	{
		free(--format);
		return (write_precision_base(nb, size, count, base));
	}
	else if (*format == '0')
	{
		free(--format);
		return (write_zero_base(nb, size, count, base));
	}
	else if (*format == 'x' || *format == 'X')
	{
		free(--format);
		return (write_left_base(nb, size, count, base));
	}
	return (-1);
}
