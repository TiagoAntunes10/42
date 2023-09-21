/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:38:35 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:38:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
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

	x = ft_str_is_lowercase("aqswdefrgtgyhjuui");
	printf("%d\n", x);
	x = ft_str_is_lowercase("qsAwdefrgtgyhjuui");
	printf("%d\n", x);
        x = ft_str_is_lowercase("111efrgtgyhjuui");
        printf("%d\n", x);
	x = ft_str_is_lowercase("");
        printf("%d\n", x);
}
