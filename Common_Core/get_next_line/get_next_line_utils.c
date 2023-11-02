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

int	write_line(char *str, int fd)
{
	int	check;

	check = read(fd, str, BUFFER_SIZE);
	if (check == -1 || check == 0)
		return (-1);
	return (check);
}

unsigned int	line_len(char *str)
{
	unsigned int	size;

	size = 0;
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n')
		str++;
	return (str);
}

char	*write_line(char *str, unsigned int size)
{
	char			*line;
	unsigned int	i;

	line = malloc(size + 1);
	if (line == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}