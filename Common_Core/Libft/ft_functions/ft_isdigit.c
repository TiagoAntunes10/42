/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_is'digiteric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:00:09 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/30 18:00:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}

/*int	main(void)
{
	char	c;

	c = '6';
	printf("ft_isdigit: %d\n", ft_isdigit(c));
	printf("isdigit: %d\n", isdigit(c));
}*/
