/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:51:59 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/07 16:35:06 by ede-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>*/

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31)
		{
			printf("\\0%x", str[i]);
		}
		else
		{
			printf("%c", str[i]);
		}
		i++;
	}
}
/*
int	main(void)
{
	ft_putstr_non_printable("Esta\nes una prueba");
	return (0);
}*/
