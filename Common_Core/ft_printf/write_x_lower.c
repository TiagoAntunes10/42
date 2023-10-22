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
	int	nb;

	nb = va_arg(valst, int);
	count += ft_putnbr_base(nb, "0123456789abcdef");
	return (count);
}
