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

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int     main(void)
{
        char    c;

        c = 'h';
        printf("ft_isalpha: %d\n", ft_isalpha(c));
		printf("isalpha: %d\n", isalpha(c));
}*/
