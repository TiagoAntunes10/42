/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:00:09 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/30 18:00:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	a;

	while (*str != '\0')
	{
		a = *str;
		if (a >= 48 && a <= 57)
			str += 1;
		else
			return (0);
	}
	return (1);
}

/*int	main(void)
{
	char	*str;
	int	i;

	str = "3784hj127";
	i = ft_str_is_numeric(str);
	printf("%d\n", i);
}*/
