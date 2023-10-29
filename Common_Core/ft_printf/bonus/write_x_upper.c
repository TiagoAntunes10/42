/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:27:08 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:27:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_x_upper(va_list valst, int count, char *format)
{
	unsigned int	nb;

	nb = va_arg(valst, unsigned int);
	if (*format == '-' || *format == '.' || *format == '0')
		return (count + write_base_bonus(nb, 0, format, "0123456789ABCDEF"));
	else if (*format == '#')
	{
		if (nb == 0)
			return (count + write_base_extra_bonus(nb, 0,
				++format, "0123456789ABCDEF"));
		else
		{
			ft_putstr_fd("0X", 1);
			return (count + write_base_extra_bonus(nb, 2, ++format,
					"0123456789ABCDEF"));
		}
	}
	else if (*format == 0)
	{
		count += ft_putnbr_base(nb, "0123456789ABCDEF");
		return (count);
	}
	return (count);
}
