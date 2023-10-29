/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:47:49 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/26 16:47:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	write_char(unsigned int size, char c)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

void	write_nbr(unsigned long int nb, int fd)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (div == 0)
	{
		mod += 48;
		write(fd, &mod, 1);
		return ;
	}
	else
		write_nbr(div, fd);
	mod += 48;
	write(fd, &mod, 1);
	return ;
}

long int	check_precision(char *format)
{
	while (*format != '\0')
	{
		if (*format == '.')
			return (ft_atoi(format + 1));
		format++;
	}
	return (-1);
}
