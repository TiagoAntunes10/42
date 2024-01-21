/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:39:02 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/21 21:56:51 by tialbert         ###   ########.fr       */
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
		while (*str == c || *str == '"' || *str == '\'')
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

int	check_quote(const char *str)
{
	if (*(str - 1) == '\\' && *str == '\\'
		&& (*(str + 1) == '\'' || *(str + 1) == '\"'))
		return (1);
	return (0);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str != '\0')
			count++;
		if (*str == '\"' || *str == '\'')
		{
			while (*str != 0)
			{
				str++;
				if (check_quote(str) == 1)
				{
					str += 2;
					break ;
				}
			}
		}
		while (*str != c && *str != '\0')
			str++;
	}
	return (count);
}

// TODO: Find error in wordlen function
static int	ft_wordlen(char const *str, char c)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		if (*(str - 1) == '\"' || *(str - 1) == '\'')
		{
			while (*str != 0)
			{
				l++;
				if (check_quote(str) == 1)
				{
					str += 2;
					break ;
				}
				str++;
			}
			l--;
		}
		if (*str == c || *str == 0)
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
