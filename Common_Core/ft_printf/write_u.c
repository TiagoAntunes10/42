/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:52 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	write_u(va_list valst, int count, char *format)
{
	unsigned int	nb;

	nb = va_arg(valst, unsigned int);
	if (*format == '-' || *format == '.' || *format == '0')
		return (count + write_nb_bonus(nb, 0, format));
	else if (*format == 0)
	{
		ft_putnbr_fd(nb, 1);
		return (count + nb_len(nb));
	}
	return (-1);
}
