/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:02:21 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:39:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int     main(void)
{
        int x;

        x = ft_str_is_printable("SD  %41^&*(}?|ERT");
        printf("%d\n", x);
        x = ft_str_is_printable("qsAwdefrgtgyhjuui");
        printf("%d\n", x);
        x = ft_str_is_printable("\n");
        printf("%d\n", x);
        x = ft_str_is_printable("");
        printf("%d\n", x);
}

