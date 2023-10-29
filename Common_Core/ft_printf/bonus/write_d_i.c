/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:15 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	write_plus_bonus(int long nb, int count, char *format,
							long int size_precision);
static int	write_non_plus_bonus(int long nb, int count, char *format,
								long int size_precision);

int	write_d_i(va_list valst, int count, char *format)
{
	int			nb;
	long int	size_precision;

	nb = va_arg(valst, int);
	size_precision = check_precision(format);
	if (size_precision < nb_len(nb * (-1)) && size_precision > 0)
		size_precision = nb_len(nb * (-1));
	if (*format == '-' || *format == '.' || *format == '0'
		|| ft_isdigit(*format) > 0)
		return (count + write_non_plus_bonus(nb, 0, format, size_precision));
	else if (*format == '+' || *format == ' ')
	{
		if (nb < 0)
			return (count + write_plus_bonus(nb, 0, ++format, size_precision));
		else
			ft_putchar_fd(*format, 1);
		return (count + write_plus_bonus(nb, 1, ++format, size_precision));
	}
	else if (*format == 0)
	{
		ft_putnbr_fd(nb, 1);
		return (count + nb_len(nb));
	}
	return (count);
}

static int	flag_condition(int long nb, int count, char *format,
						long int size_precision)
{
	unsigned int	size;

	size = ft_atoi(format + 1);
	if (*format == '-')
	{
		free(--format);
		return (write_left_nb(nb, size, count, size_precision));
	}
	else if (*format == '0')
	{
		free(--format);
		return (write_zero_nb(nb, size, count, size_precision));
	}
	return (-1);
}

static int	write_plus_bonus(int long nb, int count, char *format,
							long int size_precision)
{
	unsigned int	size;

	if (*format == '-' || *format == '0')
		return (flag_condition(nb, count, format, size_precision));
	else if (*format == '.')
	{
		free(--format);
		return (write_precision_nb(nb, size_precision, count));
	}
	else if (ft_isdigit(*format) > 0)
	{
		size = ft_atoi(format);
		free(--format);
		return (write_left_space(nb, size, count, size_precision));
	}
	else if (*format == 'i' || *format == 'd')
	{
		free(--format);
		return (write_left_nb(nb, 0, count, size_precision));
	}
	return (-1);
}

static int	write_non_plus_bonus(int long nb, int count, char *format,
								long int size_precision)
{
	unsigned int	size;

	if (ft_isdigit(*format) > 0 && *format != '0')
	{
		size = ft_atoi(format);
		free(format);
		return (write_left_space(nb, size, count, size_precision));
	}
	size = ft_atoi(format + 1);
	if (*format == '-')
	{
		free(format);
		return (write_left_nb(nb, size, count, size_precision));
	}
	else if (*format == '.')
	{
		free(format);
		return (write_precision_nb(nb, size_precision, count));
	}
	else if (*format == '0')
	{
		free(format);
		return (write_zero_nb(nb, size, count, size_precision));
	}
	return (-1);
}
