/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:32 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	write_i(va_list valst, int count)
{
	int	nb;

	nb = va_arg(valst, int);
	ft_putnbr_fd(nb, 1);
	return (count + nb_len(nb));
}
