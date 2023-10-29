/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:19:44 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/28 14:19:45 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	write_left_unsigned(unsigned long int nb, unsigned int size, int count)
{
	write_nbr(nb, 1);
	if (size <= (unsigned int)(nb_len(nb) + count))
		return ((nb_len(nb) + count));
	else
	{
		write_char(size - (nb_len(nb) + count), ' ');
		return (size);
	}
}

static int	write_precision_unsigned(unsigned long int nb, unsigned int size, int count)
{
	if (size == 0 && nb == 0)
		return (count);
	else if (size <= (unsigned int)(nb_len(nb) + count))
	{
		write_nbr(nb, 1);
		return ((nb_len(nb) + count));
	}
	else
	{
		write_char(size - (nb_len(nb) + count), '0');
		write_nbr(nb, 1);
		return (size);
	}
}

static int	write_zero_unsigned(unsigned long int nb, unsigned int size, int count)
{
	if (size <= (unsigned int)(nb_len(nb) + count))
	{
		write_nbr(nb, 1);
		return ((nb_len(nb) + count));
	}
	else
	{
		write_char(size - (nb_len(nb) + count), '0');
		write_nbr(nb, 1);
		return (size);
	}
}

int	write_unsigned_bonus(unsigned long int nb, int count, char *format)
{
	unsigned int	size;

	size = ft_atoi(format + 1);
	if (*format == '-')
	{
		free(format);
		return (write_left_unsigned(nb, size, count));
	}
	else if (*format == '.')
	{
		free(format);
		return (write_precision_unsigned(nb, size, count));
	}
	else if (*format == '0')
	{
		free(format);
		return (write_zero_unsigned(nb, size, count));
	}
	return (-1);
}
