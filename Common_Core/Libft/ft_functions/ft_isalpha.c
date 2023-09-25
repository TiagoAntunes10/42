/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:56:20 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/30 17:57:00 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <ctype.h>

int	ft_isalpha(int c);

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}

/*int     main(void)
{
        char    c;
		int	i;

        c = "A";
        printf("ft_isalpha: %d\n", ft_isalpha(c));
		printf("isalpha: %d\n", isalpha(c));
}*/
