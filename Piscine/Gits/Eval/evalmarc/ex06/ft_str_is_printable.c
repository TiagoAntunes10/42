/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:31:46 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/08 09:04:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	p;

	p = 0;
	if (str[p] == '\0')
	{
		return (1);
	}
	while (str[p] != '\0')
	{
		if (!(str[p] >= 32 && str[p] <= 126))
		{
			return (0);
		}
		p++;
	}
	return (1);
}

int	main(void)
{
	char	*m;

	m  = "sabdh\n";
	ft_str_is_printable(m);
	printf("%d\n", ft_str_is_printable(m));
}

