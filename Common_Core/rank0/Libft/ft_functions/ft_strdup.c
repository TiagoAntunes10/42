/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:07:16 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/11 17:44:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	unsigned int		l;
	char				*str;

	l = ft_strlen(src);
	str = malloc (l + 1);
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, src, l + 1);
	return (str);
}
