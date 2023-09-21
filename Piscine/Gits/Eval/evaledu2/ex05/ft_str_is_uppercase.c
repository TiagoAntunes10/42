/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:38:35 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:38:32 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}


int	main(void)
{
	int x;

	x = ft_str_is_uppercase("SDFSDSFWTRTERT");
	printf("%d\n", x);
	x = ft_str_is_uppercase("qsAwdefrgtgyhjuui");
	printf("%d\n", x);
        x = ft_str_is_uppercase("111 efrgtgyhjuui");
        printf("%d\n", x);
	x = ft_str_is_uppercase("");
        printf("%d\n", x);
}
