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

int	write_p(va_list valst, int count, char *format)
{
	unsigned long long	ptr;

	(void) format;
	ptr = va_arg(valst, unsigned long long);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (count + 5);
	}
	count += write_ptr(ptr, "0123456789abcdef", 16);
	return (count);
}
