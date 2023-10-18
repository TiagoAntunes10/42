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
#include "libftprintf.h"

int	write_s(va_list valst, int count)
{
	char	*str;

	str = va_arg(valst, char *);
	ft_putstr_fd(str, 1);
	return (count + ft_strlen(str));
}
