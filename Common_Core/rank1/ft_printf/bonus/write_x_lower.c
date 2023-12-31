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

static int	write_base_bonus_x(unsigned long int nb, int count, char *format,
				long int size_precision);
static int	write_base_extra_bonus_x(unsigned long int nb, int count,
				char *format, long int size_precision);

int	write_x_lower(va_list valst, int count, char *format)
{
	unsigned int	nb;
	long int		size_precision;

	nb = va_arg(valst, unsigned int);
	size_precision = check_precision(format);
	if (size_precision < base_len(nb) && size_precision >= 0 && nb != 0)
		size_precision = base_len(nb);
	if (*format == '-' || *format == '.' || ft_isdigit(*format) > 0)
		return (count + write_base_bonus_x(nb, 0, format, size_precision));
	else if (*format == '#')
	{
		if (nb == 0)
			return (count + write_base_extra_bonus_x(nb, 0,
					++format, size_precision));
		else
		{
			ft_putstr_fd("0x", 1);
			return (count + write_base_extra_bonus_x(nb, 2,
					++format, size_precision));
		}
	}
	else if (*format == 0)
		return (count + ft_putnbr_base(nb, "0123456789abcdef"));
	return (count);
}

static int	flag_condition(int long nb, int count, char *format,
						long int size_precision)
{
	unsigned int	size;

	if (*format == '-')
	{
		size = ft_atoi(format + skip_minus(format));
		free(--format);
		return (write_left_base_x(nb, size, count, size_precision));
	}
	else if (*format == '0')
	{
		size = ft_atoi(format + 1);
		free(--format);
		return (write_zero_base_x(nb, size, count, size_precision));
	}
	return (-1);
}

static int	write_base_bonus_x(unsigned long int nb, int count, char *format,
					long int size_precision)
{
	unsigned int	size;

	if (ft_isdigit(*format) > 0 && *format != '0')
	{
		size = ft_atoi(format);
		free(format);
		if (size_precision == 0 && nb != 0)
			return (write_space_base_x(nb, (size - base_len(nb)), count,
					size_precision));
		return (write_space_base_x(nb, size, count, size_precision));
	}
	if (*format == '-')
	{
		size = ft_atoi(format + skip_minus(format));
		count += write_left_base_x(nb, size, count, size_precision);
	}
	else
		size = ft_atoi(format + 1);
	if (*format == '.')
		count += write_precision_base_x(nb, size, count);
	else if (*format == '0')
		count += write_zero_base_x(nb, size, count, size_precision);
	free(format);
	return (count);
}

static int	write_base_extra_bonus_x(unsigned long int nb, int count,
				char *format, long int size_precision)
{
	unsigned int	size;

	if (*format == '-' || *format == '0')
		return (flag_condition(nb, count, format, size_precision));
	else if (*format == '.')
	{
		free(--format);
		return (write_precision_base_x(nb, size_precision, count));
	}
	else if (ft_isdigit(*format) > 0)
	{
		size = ft_atoi(format);
		free(--format);
		if (size_precision == 0 && nb != 0)
			return (write_space_base_x(nb, (size - base_len(nb)), count,
					size_precision));
		return (write_space_base_x(nb, size, count, size_precision));
	}
	else if (*format == 'x' || *format == 'X')
	{
		free(--format);
		return (write_left_base_x(nb, 0, count, size_precision));
	}
	return (-1);
}
