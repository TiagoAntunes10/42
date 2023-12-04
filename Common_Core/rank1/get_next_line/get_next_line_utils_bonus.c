/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:47:18 by tialbert          #+#    #+#             */
/*   Updated: 2023/11/14 11:47:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_line(char *str, int fd)
{
	int	check;
	int	i;

	check = read(fd, str, 1);
	if (check == -1 || check == 0)
	{
		ft_bzero(str, 1);
		return (check);
	}
	i = 1;
	while (i < (BUFFER_SIZE) && *str != '\n')
	{
		str++;
		check = read(fd, str, 1);
		if (check == -1 || check == 0)
			break ;
		i++;
	}
	if (check > 0)
		str++;
	*str = 0;
	return (check);
}

unsigned int	line_len(char *str)
{
	unsigned int	size;

	size = 0;
	while (str[size] != '\n' && str[size] != '\0')
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}

char	*write_line(char *str, char *str2)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	line = malloc(line_len(str) + line_len(str2) + 1);
	if (line == 0)
		return (NULL);
	i = 0;
	while (str2[i] != '\0')
	{
		line[i] = str2[i];
		i++;
	}
	j = 0;
	while (i < (line_len(str) + line_len(str2)))
	{
		line[i] = str[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (line);
}

int	cpy_str(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (i);
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
