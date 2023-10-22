/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:02:53 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/19 09:02:55 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	write_base(long int nb, char *base, int div);

int	nb_len(int long nb)
{
	int	l;

	l = 0;
	if (nb < 0)
	{
		l = 1;
		nb *= -1;
	}
	if (nb / 10 == 0)
		return (1);
	l += 1;
	l += nb_len(nb / 10);
	return (l);
}

int	ft_putnbr_base(int nb, char *base)
{
	long int	nbr;
	int			count;

	nbr = nb;
	count = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
		count++;
	}
	count += write_base(nbr, base, 16);
	return (count);
}

static int	write_base(long int nb, char *base, int div)
{
	int		count;

	count = 1;
	if ((nb / div) == 0)
	{
		ft_putchar_fd(base[nb % div], 1);
		return (1);
	}
	count += write_base((nb / div), base, div);
	ft_putchar_fd(base[nb % div], 1);
	return (count);
}

int	write_ptr(unsigned long long ptr, char *base, int div)
{
	int		count;

	count = 1;
	if ((ptr / div) == 0)
	{
		ft_putchar_fd(base[ptr % div], 1);
		return (1);
	}
	count += write_ptr((ptr / div), base, div);
	ft_putchar_fd(base[ptr % div], 1);
	return (count);
}
