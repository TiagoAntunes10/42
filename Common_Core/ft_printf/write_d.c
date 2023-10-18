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
#include "libftprintf.h"

int	write_d(va_list valst, int count)
{
	double	nb;

	nb = va_arg(valst, double);
	//write_double(nb, 6);
	return (count + nb_len(nb) + 7);
}
