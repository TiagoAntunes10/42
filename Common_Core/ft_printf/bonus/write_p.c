/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:39 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:41 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	write_space(unsigned int size, unsigned int count2);
static int	write_left_ptr(unsigned long long ptr, char *format);

int	write_p(va_list valst, int count, char *format)
{
	unsigned long long	ptr;

	ptr = va_arg(valst, unsigned long long);
	if (ptr == 0)
	{
		if (*format != 0)
			free(format);
		ft_putstr_fd("(nil)", 1);
		return (count + 5);
	}
	else if (*format == '-' || ft_isdigit(*format) > 0)
	{
		return (count + write_left_ptr(ptr, format));
	}
	else if (*format == 0)
	{
		count += write_ptr(ptr, "0123456789abcdef", 16);
		return (count);
	}
	return (count);
}


static int	write_left_ptr(unsigned long long ptr, char *format)
{
	unsigned int	size;
	unsigned int	count2;

	count2 = write_ptr(ptr, "0123456789abcdef", 16);
	if (*format == '-')
	{
		size = ft_atoi(format + 1);
		free(format);
		return (write_space(size, count2));
	}
	else if (ft_isdigit(*format) > 0)
	{
		size = ft_atoi(format);
		free(format);
		return (write_space(size, count2));
	}
	return (0);
}

static int	write_space(unsigned int size, unsigned int count2)
{
	if ((count2) >= size)
		return (count2);
	else
	{
		write_char((size - count2), ' ');
		return (size);
	}
}
