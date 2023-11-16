/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:19 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/31 13:55:20 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(char *buffer, char **char_lake, int fd)
{
	char	*temp;
	int		check;

	check = 1;
	while (ft_strchr(*char_lake, '\n') == NULL && check > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1 || buffer == NULL)
		{
			free(*char_lake);
			*char_lake = NULL;
			return (check);
		}
		if (check == 0)
			return (check);
		temp = ft_strjoin(*char_lake, buffer);
		free(*char_lake);
		*char_lake = temp;
	}
	return (check);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*cs;

	i = 0;
	cs = (char *) s;
	while (i < n)
	{
		cs[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			j;
	char		*str;

	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == 0)
		return (NULL);
	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			str[j] = *s1;
			s1++;
			j++;
		}
	}
	while (*s2 != '\0')
	{
		str[j] = *s2;
		s2++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

size_t	ft_strlen(char const *str)
{
	int	l;

	if (str == NULL)
		return (0);
	l = 0;
	while (*str != '\0')
	{
		++l;
		++str;
	}
	return (l);
}

char	*ft_strchr(char const *s, int c)
{
	char	*cs;

	cs = (char *) s;
	if (cs == NULL)
		return (NULL);
	while (*cs != '\0')
	{
		if (*cs == (unsigned char) c)
			return (cs);
		else
			cs++;
	}
	if (*cs == (unsigned char) c)
		return (cs);
	else
		return (NULL);
}
