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
	int	nb;

	nb = va_arg(valst, int);
	count += ft_putnbr_base(nb, "0123456789ABCDEF");
	return (count);
}
