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

int	get_line(char *str, int fd)
{
	int	check;
	int i;

	i = 0;
	while (i < BUFFER_SIZE && *str != '\n')
	{
		check = read(fd, str, 1);
		if (check == -1 || check == 0)
			break ;
		i++;
		str++;
	}
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

char	*write_line(char *str, char *str2, unsigned int size)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	line = malloc(size + 1);
	if (line == 0)
		return (NULL);
	i = 0;
	while (str2[i] != '\0')
	{
		line[i] = str2[i];
		i++;
	}
	j = 0;
	while (i < size)
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

char	*str_start(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	if (i >= 0 && *(str - 1) != '\0')
		return (str - BUFFER_SIZE);
	else
		return (str);
}
