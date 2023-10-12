/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:38:20 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:38:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	char			*cdest;
	char			*csrc;
	unsigned int	i;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	cdest = (char *) dest;
	csrc = (char *) src;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
