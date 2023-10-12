/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:39:02 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:39:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_words(char const *str, char c);
static int		ft_wordlen(char const *str, char c);

char	**ft_split(char const *str, char c)
{
	int		count;
	char	**words;
	int		len;

	count = count_words(str, c);
	words = ft_calloc(count + 1, sizeof(char *));
	if (words == 0)
		return (NULL);
	while (*str != '\0')
	{
		len = ft_wordlen(str, c);
		if (len == 0)
		{
			str += 1;
			continue ;
		}
		*words = malloc(len + 1);
		ft_strlcpy(*words, str, len + 1);
		str += len;
		words++;
	}
	words -= count;
	words[count] = malloc(0);
	free(words[count]);
	return (words);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		else if (str[i] != c && str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *str, char c)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		if (*str == c)
			break ;
		l++;
		str++;
	}
	return (l);
}
