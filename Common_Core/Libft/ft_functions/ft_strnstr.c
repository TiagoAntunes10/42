/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:39:35 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/08 10:10:06 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_str(char *str, char *to_find);

char	*ft_strnstr(char *str, char *to_find, unsigned int n)
{
	int				i;
	unsigned int	j;

	if (*to_find == '\0')
		return (str);
	j = 0;
	while (j < n)
	{
		i = 0;
		if (*to_find == *str)
			i = find_str(str, to_find);
		else
			str += 1;
		if (*(to_find + i) == '\0')
			return (str);
		else
			str += i;
		j++;
	}
	return ("\0");
}

int	find_str(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (*to_find == *str && *to_find != '\0')
	{
		to_find += 1;
		str += 1;
		i++;
	}
	return (i);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*to_find;

	str = "teteste";
	to_find = "teste";
	printf("%s\n", ft_strnstr(str, to_find, 8));
}*/
