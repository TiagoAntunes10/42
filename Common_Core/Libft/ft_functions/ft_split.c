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
	int		i;

	count = count_words(str, c);
	words = malloc((count + 1) * sizeof(char *));
	if (words == 0)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		len = ft_wordlen(str, c);
		if (len == 0)
		{
			str += 1;
			continue ;
		}
		words[i] = malloc(len + 1);
		ft_strlcpy(words[i], str, len + 1);
		str += len;
		i++;
	}
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

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**words;
	int		i;

	if (argc != 3)
		return (0);
	words = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (words[i][0] != '\0')
	{
		printf("%s\n", words[i]);
		i++;
	}
}*/
