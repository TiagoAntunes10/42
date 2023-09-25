/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:01:13 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/01 11:09:04 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	a;

	while (*str != '\0')
	{
		a = *str;
		if (a >= 32)
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

	str = "ASBSDHBsfdSHJB\n";
	i = ft_str_is_printable(str);
	printf("%d\n", i);
}*/
