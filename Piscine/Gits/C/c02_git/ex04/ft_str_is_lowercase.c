/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:00:26 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/01 11:07:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	a;

	while (*str != '\0')
	{
		a = *str;
		if (a >= 97 && a <= 122)
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

	str = "hsav6bdhv";
	i = ft_str_is_lowercase(str);
	printf("%d\n", i);
}*/
