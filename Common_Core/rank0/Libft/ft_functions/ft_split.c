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

#include "libft.h"

static int		count_words(char const *str, char c);
static int		ft_wordlen(char const *str, char c);
static char		**free_words(char **words, char **words_temp);

char	**ft_split(char const *str, char c)
{
	int		count;
	char	**words;
	char	**words_temp;
	int		len;

	count = count_words(str, c);
	words = (char **) malloc(sizeof(char *) * (count + 1));
	if (words == 0)
		return (NULL);
	words_temp = words;
	while (*str != '\0' && *(str + 1) != '\0')
	{
		while (*str == c)
			str += 1;
		if (*str == '\0')
			break ;
		len = ft_wordlen(str, c);
		*words_temp = ft_substr(str, 0, len);
		if (*words_temp == 0)
			return (free_words(words, words_temp));
		str += len;
		words_temp++;
	}
	*words_temp = NULL;
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
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
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

static char	**free_words(char **words, char **words_temp)
{
	while (words <= words_temp)
	{
		free(*words_temp);
		words_temp--;
	}
	free(words);
	return (NULL);
}
