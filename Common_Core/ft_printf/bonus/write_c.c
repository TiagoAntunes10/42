/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:24 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_c(va_list valst, int count, char *format)
{
	unsigned int	size;

	if (*format == '-' || *format == '.')
	{
		size = ft_atoi(format + 1);
		free(format);
		ft_putchar_fd(va_arg(valst, int), 1);
		if (size > 0)
		{
			write_char(size - 1, ' ');
			return (count + size - 1);
		}
		return (count++);
	}
	else if (*format == 0)
	{
		ft_putchar_fd(va_arg(valst, int), 1);
		return (count++);
	}
	return (count);
}
