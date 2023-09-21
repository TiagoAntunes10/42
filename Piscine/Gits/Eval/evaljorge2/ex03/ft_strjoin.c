/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:10:49 by masoares          #+#    #+#             */
/*   Updated: 2023/09/10 10:31:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strcat(char	*str, char	*strs, int k);
int	ft_strlens(char	**str);
int	ft_strlen(char	*str);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		tlen;
	int		k;

	i = 1;
	if (size == 0)
	{
		str = (char *) malloc (1);
		str[0] = '\0';
	}
	while (i++ < size)
		tlen = ft_strlens(strs);
	str = (char *) malloc ((ft_strlen(sep) * (size - 1)) + tlen + 1);
	i = 1;
	while (i <= size)
	{
		k = ft_strcat(str, strs[i], k);
		if (i < size)
			k = ft_strcat(str, sep, k);
		i++;
	}
	str[k + 1] = '\0';
	return (str);
}

int	ft_strcat(char	*str, char	*strs, int k)
{
	int		j;

	j = 0;
	while (strs[j] != '\0')
	{
		str[k] = strs[j];
		j++;
		k++;
	}
	return (k);
}

int	ft_strlens(char **str)
{
	int	i;
	int	j;
	int	sv;

	sv = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			sv++;
		}
		i++;
	}
	return (sv);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	char	*sep = "///////////";
	char	*str;

	str = ft_strjoin(ac - 1, av, sep);
	printf("%s\n", str);
	free(str);
}
