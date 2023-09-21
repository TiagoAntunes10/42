/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:24:58 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:37:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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

        x = ft_str_is_numeric("1234567890");
        printf("%i\n", x);
        x = ft_str_is_numeric("123 fgd");
        printf("%i\n", x);
        x  = ft_str_is_numeric("");
        printf("%i\n", x);
        x = ft_str_is_numeric(" wdw6787b /;';'");
        printf("%i\n", x);

        return (0);
}

