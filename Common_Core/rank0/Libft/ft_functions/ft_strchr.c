/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:39:23 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:39:24 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	char	*cs;

	cs = (char *) s;
	while (*cs != '\0')
	{
		if (*cs == (unsigned char) c)
			return (cs);
		else
			cs++;
	}
	if (*cs == (unsigned char) c)
		return (cs);
	else
		return (NULL);
}
