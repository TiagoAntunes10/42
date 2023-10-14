/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:36:54 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/08 10:12:58 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 1;
	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	while (i <= n)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		else if (*cs1 == '\0' || *cs2 == '\0')
			break ;
		cs1 += 1;
		cs2 += 1;
		i++;
	}
	return (0);
}
