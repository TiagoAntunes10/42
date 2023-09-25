/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.int c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:01:13 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/01 11:09:04 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c);

int	ft_isprint(int c)
{
	if (c >= 32)
		return (c);
	else
		return (0);
}

/*int	main(void)
{
	char	c;

	c = 'h';
	printf("ft_isprint: %d\n", ft_isprint(c));
	printf("isprint: %d\n", isprint(c));
}*/
