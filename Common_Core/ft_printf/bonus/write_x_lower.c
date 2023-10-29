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

int	write_x_lower(va_list valst, int count, char *format)
{
	unsigned int	nb;

	nb = va_arg(valst, unsigned int);
	if (*format == '-' || *format == '.' || *format == '0')
		return (count + write_base_bonus(nb, 0, format, "0123456789abcdef"));
	else if (*format == '#')
	{
		if (nb == 0)
			return (count + write_base_extra_bonus(nb, 0,
				++format, "0123456789abcdef"));
		else
		{
			ft_putstr_fd("0x", 1);
			return (count + write_base_extra_bonus(nb, 2,
					++format, "0123456789abcdef"));
		}
	}
	else if (*format == 0)
	{
		count += ft_putnbr_base(nb, "0123456789abcdef");
		return (count);
	}
	return (count);
}
