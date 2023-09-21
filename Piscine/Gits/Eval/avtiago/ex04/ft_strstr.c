/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:39:35 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/07 18:48:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	while (*str != '\0')
	{
		i = 0;
		while (*to_find == *str && *to_find != '\0')
		{
			to_find += 1;
			str += 1;
			i++;
		}
		if (*to_find == '\0')
		{
			str -= i;
			return (str);
		}
		to_find -= i;
		str += 1;
	}
	return ("\0");
}

#include <stdio.h>
int	main(void)
{
	char	*str;
	char	*to_find;

	str = "teteste";
	to_find = "teste";
	printf("%s\n", ft_strstr(str, to_find));
}
