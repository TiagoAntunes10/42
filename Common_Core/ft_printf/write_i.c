/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:32 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	write_i(va_list valst, int count, char *format)
{
	int	nb;

	nb = va_arg(valst, int);
	if (*format == '-' || *format == '.' || *format == '0')
		return (count + write_nb_bonus(nb, 0, format));
	else if (*format == '+')
	{
		if (nb >= 0)
			ft_putchar_fd('+', 1);
		return (count + write_nb_bonus(nb, 1, ++format));
	}
	else if (*format == ' ')
	{
		if (nb >= 0)
			ft_putchar_fd(' ', 1);
		return (count + write_nb_bonus(nb, 1, ++format));
	}
	else if (*format == 0)
	{
		if (nb < 0)
			count++;
		ft_putnbr_fd(nb, 1);
		return (count + nb_len(nb));
	}
	return (-1);
}
