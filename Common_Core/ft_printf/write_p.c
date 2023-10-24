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
#include "ft_printf_bonus.h"

int	write_p(va_list valst, int count, char *format)
{
	unsigned long long	ptr;
	unsigned int		size;
	unsigned int		count2;

	ptr = va_arg(valst, unsigned long long);
	if (*format == '-')
	{
		count2 = write_ptr(ptr, "0123456789abcdef", 16);
		size = ft_atoi(format + 1);
		free(format);
		if ((count2 + 2) >= size)
			return (count + count2 + 2);
		else
		{
			write_char((size - (count2 + 2)), ' ');
			return (count + size);
		}
	}
	else if (*format == 0)
	{
		count += write_ptr(ptr, "0123456789abcdef", 16);
		return (count + 2);
	}
	return (-1);
}
