/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:34:24 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:34:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	c;

	c = 56;
	printf("ft_isascii: %d\n", ft_isascii(c));
	printf("isascii: %d\n", isascii(c));
}*/
