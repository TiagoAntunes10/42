/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:15 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_d(va_list valst, int count, char *format)
{
	int	nb;

	nb = va_arg(valst, int);
	if (nb < 0)
		count++;
	ft_putnbr_fd(nb, 1);
	return (count + nb_len(nb));
}
