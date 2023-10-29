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

static void	write_nbr(unsigned long int nb, int fd);

int	write_u(va_list valst, int count, char *format)
{
	unsigned int	nb;

	(void) format;
	nb = va_arg(valst, unsigned int);
	write_nbr(nb, 1);
	return (count + nb_len(nb));
}

static void	write_nbr(unsigned long int nb, int fd)
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
