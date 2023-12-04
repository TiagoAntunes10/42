/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:56:13 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/30 21:56:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*cs;
	unsigned char		chr;

	cs = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (cs[i] == chr)
		{
			cs += i;
			return (cs);
		}
		else
			i++;
	}
	return (NULL);
}
