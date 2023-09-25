/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:20 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/30 17:57:00 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	a;

	while (*str != '\0')
	{
		a = *str;
		if (a >= 65 && a <= 91)
			str += 1;
		else if (a >= 97 && a <= 122)
			str += 1;
		else
			return (0);
	}
	return (1);
}

/*int     main(void)
{
        char    *str;
	int	i;

        str = "Adhd76a";
        i = ft_str_is_alpha(str);
        printf("%d\n", i);
}*/
