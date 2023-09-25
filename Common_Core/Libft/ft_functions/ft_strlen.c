/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:47:40 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/28 12:32:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//#include <string.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		++l;
		++str;
	}
	return (l);
}

/*int	main(void)
{
	char	*str;

	str = "abcd";
	printf("%d\n", ft_strlen(str));
	printf("%d\n", strlen(str));

}*/
