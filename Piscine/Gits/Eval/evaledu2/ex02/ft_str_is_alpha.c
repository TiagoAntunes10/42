/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:38:49 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:36:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int     main (void)
{
        int     x;

	x = ft_str_is_alpha("qweeqwADFDrrrsdfsd");
        printf("%i\n", x);
        x = ft_str_is_alpha("sdaqq1");
        printf("%i\n", x);
        x  = ft_str_is_alpha("");
        printf("%i\n", x);
        x = ft_str_is_alpha(" wdw6787b /;';'");
        printf("%i\n", x);

        return (0);
}
