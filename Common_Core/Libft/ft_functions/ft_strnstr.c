/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:39:34 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/06 21:39:36 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_str(char const *big,
				char const *small, size_t len, size_t count);

char	*ft_strnstr(char const *big, char const *small, size_t len)
{
	int				i;
	unsigned int	j;

	j = 0;
	if (*small == '\0')
		return ((char *) big);
	else if (*big == '\0')
		return (NULL);
	while (j < len)
	{
		i = 0;
		if (*small == *big)
			i = find_str(big, small, len, j);
		if (*(small + i) == '\0')
			return ((char *) big);
		else
			big++;
		j++;
	}
	return (NULL);
}

static int	find_str(char const *big,
				char const *small, size_t len, size_t count)
{
	int	i;

	i = 0;
	while (*small == *big && *small != '\0' && count < len)
	{
		small += 1;
		big += 1;
		i++;
		count++;
	}
	return (i);
}
