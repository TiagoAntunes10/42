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

static int	write_left_str(char *str, unsigned int size);
static int	write_precision_str(char *str, unsigned int size);

int	write_s(va_list valst, int count, char *format)
{
	char			*str;
	unsigned int	size;

	str = va_arg(valst, char *);
	if (*format == '-')
	{
		size = ft_atoi(format + 1);
		free(format);
		return (count + write_left_str(str, size));
	}
	else if (*format == '.')
	{
		size = ft_atoi(format + 1);
		free(format);
		return (count + write_precision_str(str, size));
	}
	else if (*format == 0)
	{
		ft_putstr_fd(str, 1);
		return (count + ft_strlen(str));
	}
	return (-1);
}

static int	write_left_str(char *str, unsigned int size)
{
		ft_putstr_fd(str, 1);
		if (size <= (unsigned int) ft_strlen(str))
			return (ft_strlen(str));
		else
		{
			write_char(size - ft_strlen(str), ' ');
			return (size);
		}
}

static int	write_precision_str(char *str, unsigned int size)
{
	if (size <= (unsigned int) ft_strlen(str))
	{
		str = ft_substr(str, 0, size);
		ft_putstr_fd(str, 1);
		free(str);
		return (size);
	}
	else
	{
		write_char(size - ft_strlen(str), ' ');
		return (size);
	}
}
