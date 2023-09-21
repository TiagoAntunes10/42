/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:36:56 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/08 09:02:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	p;

	p = 0;
	if (str[p] == '\0')
	{
		return (1);
	}
	while (str[p] != '\0')
	{
		if ((str[p] >= 'a' && str[p] <= 'z')
			|| (str[p] >= 'A' && str[p] <= 'Z'))
		{
			p++;
		}
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	char	*m;

	m  = "djnbuib";
	ft_str_is_alpha(m);
	printf("%d\n", ft_str_is_alpha(m));
}

