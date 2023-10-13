/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:32:36 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:32:37 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmem, size_t size)
{
	char			*arr;
	long int		n;
	unsigned int	i;

	if (nmem == 0 || size == 0)
		return (NULL);
	n = nmem * size;
	if (n > 2147483647)
		return (NULL);
	arr = (char *) malloc (nmem * size);
	if (arr == 0)
		return (NULL);
	i = 0;
	while (i < nmem)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
