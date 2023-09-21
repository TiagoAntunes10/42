/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:24:36 by mde-souz          #+#    #+#             */
/*   Updated: 2023/09/11 19:33:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != '\0' && is_charset(str[i], charset) == 1)
		{
			i++;
		}
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && is_charset(str[i], charset) == 0)
		{
			i++;
		}
	}
	return (count);
}

int	lword(char *str, char *charset)
{
	int	i;

	i = 0;
	while (is_charset(str[i], charset) == 0 && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	fill_array(char *array, char *str, char *charset)
{
	int	i;

	i = 0;
	while (is_charset(str[i], charset) == 0 && str[i] != '\0')
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**mtx;

	mtx = (char **)malloc(sizeof(char *) 
			* (count_words(str, charset) + 1));
	if (!mtx)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] != '\0' && is_charset(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
		{
			mtx[j] = (char *)malloc(sizeof(char) * lword(str + i, charset) + 1);
			fill_array(mtx[j], str + i, charset);
			j++;
		}
		while (str[i] != '\0' && is_charset(str[i], charset) == 0)
			i++;
	}
	mtx[j] = 0;
	return (mtx);
}
int main ()
{
  char **mtx;
  char *str = "string1+string2+-String3--String4--";
  char *cs = "+-";
  int i = 0;
  mtx = ft_split(str, cs);
  while (mtx[i] != 0)
  {
  printf("%s\n", mtx[i]);
  i++;
  }
}
