/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:07:16 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/11 17:44:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

char	*ft_strdup(char *src)
{
	int		l;
	char	*str;

	l = ft_strlen(src);
	str = malloc (l);
	str = ft_strcpy(str, src);
	return (str);
}

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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>
int main(void)
{
	char	*src;

	src = "Boas";
	printf("%s\n", ft_strdup(src));
}*/
