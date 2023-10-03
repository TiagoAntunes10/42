/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:33:47 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:33:50 by tialbert         ###   ########.fr       */
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
