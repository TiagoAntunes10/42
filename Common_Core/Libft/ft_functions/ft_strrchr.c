/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:40:50 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:40:51 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char			*cs;
	int				len;

	cs = (char *) s;
	len = ft_strlen(cs);
	cs += len;
	while (len >= 0)
	{
		if (*cs == (unsigned char) c)
			return (cs);
		cs--;
		len--;
	}
	return (NULL);
}
