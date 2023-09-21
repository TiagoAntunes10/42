/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:00:58 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/01 11:08:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	a;

	while (*str != '\0')
	{
		a = *str;
		if (a >= 65 && a <= 90)
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

	str = "ASBSDHBsfdSHJB";
	i = ft_str_is_uppercase(str);
	printf("%d\n", i);
}*/
