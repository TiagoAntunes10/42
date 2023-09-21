/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:54:23 by mde-souz          #+#    #+#             */
/*   Updated: 2023/09/11 19:22:45 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concat;
	int		i;
	int		length;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	length = 0;
	i = 0;
	while (i < size)
	{
		length = length + ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	length = length - ft_strlen(sep) + 1;
	concat = (char *)malloc(sizeof(char) * length);
	ft_strcpy(concat, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(concat, sep);
		ft_strcat(concat, strs[i]);
		i++;
	}
	concat[length - 1] = '\0';
	return (concat);
}
#include <stdio.h>
int	main(int argc, char **argv)
{

	int	size;
	char	*sep;
	char	**strs;
	char	*str;

	(void)argc;
	(void)argv;
	strs = (char**)malloc(sizeof(strs) * 3);
	strs[0] = "Cho";
	strs[1] = "567";
	strs[2] = "str2";
	sep = "+";
	size = 3;
	str = ft_strjoin(size, strs, sep);
	printf("%d: %s\n", size, str);
}
