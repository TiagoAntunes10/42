/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:04 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:05 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int	write_spe(const char *str, va_list valst, int count)
{
	if (ft_isalpha(*str) > 0)
	{
		if (*str == 'c')
			return (write_c(valst, count));
		else if (*str == 's')
			return (write_s(valst, count));
		//else if (*str == 'p')
			//return (write_p(valst, count));
		else if (*str == 'd')
			return (write_d(valst, count));
		else if (*str == 'i')
			return (write_i(valst, count));
		//else if (*str == 'u')
			//return (write_u(valst, count));
		//else if (*str == 'x')
			//return (write_x_lower(valst, count));
		//else if (*str == 'X')
			//return (write_x_upper(valst, count));
		else
			return (-1);
	}
	else
		return (-1);
}
