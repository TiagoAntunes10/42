/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:45:09 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/11 17:49:02 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
char	*ft_join(int size, char **strs, char *sep, int together);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;

	if (size == 0)
	{
		str = malloc(0);
		return (str);
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_strlen(strs[i]);
		i++;
	}
	j += ft_strlen(sep) * (size - 1);
	str = malloc(j + 1);
	str = ft_join(size, strs, sep, j);
	str[j] = '\0';
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

char	*ft_join(int size, char **strs, char *sep, int together)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(together);
	while (i < size)
	{
		k = 0;
		while (strs[i][k] != '\0')
			str[j++] = strs[i][k++];
		k = 0;
		if (i < (size - 1))
		{
			while (sep[k] != '\0')
				str[j++] = sep[k++];
		}
		i++;
	}
	return (str);
}
/*#include <stdio.h>

int main(int argc, char **argv)
{
	char	*sep = "!!!!";
	char	*str;

	if (argc < 2)
		return (0);
	argv += 1;
	str = ft_strjoin((argc - 1), argv, sep);
	printf("%s\n", str);
}*/
