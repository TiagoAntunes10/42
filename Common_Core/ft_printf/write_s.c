/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:45 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	write_s(va_list valst, int count, char *format)
{
	char			*str;
	unsigned int	size;

	str = va_arg(valst, char *);
	if (*format == '-')
	{
		size = ft_atoi(++format);
		return (count + write_left_str(str, size));
	}
	else if (*format == '.')
	{
		size = ft_atoi(++format);
		return (count + write_precision_str(str, size));
	}
	else if (format == 0)
	{
		ft_putstr_fd(str, 1);
		return (count + ft_strlen(str));
	}
	return (-1);
}
