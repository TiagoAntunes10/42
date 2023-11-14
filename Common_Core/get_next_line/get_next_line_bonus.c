/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:46:56 by tialbert          #+#    #+#             */
/*   Updated: 2023/11/14 11:46:59 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*alloc_prob(char *str);
char	*alloc_prob2(char *str, char *str2);
char	*make_line(char *line, char *buffer, int fd);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			check;

	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		ft_bzero(buffer, BUFFER_SIZE);
		if (buffer == 0)
			return (alloc_prob(buffer));
	}
	check = read_line(buffer, fd);
	if ((check == -1 || check == 0) && *buffer == '\0')
	{
		buffer = alloc_prob(buffer);
		return (buffer);
	}
	line = malloc(1);
	if (line == 0)
		return (alloc_prob2(buffer, line));
	ft_bzero(line, 1);
	line = make_line(line, buffer, fd);
	return (line);
}

char	*alloc_prob(char *str)
{
	free(str);
	return (NULL);
}

char	*alloc_prob2(char *str, char *str2)
{
	free(str);
	free(str2);
	return (NULL);
}

char	*make_line(char *line, char *buffer, int fd)
{
	char	*temp;
	int		check;

	while (*buffer != '\0')
	{
		temp = malloc(line_len(line) + 1);
		if (temp == 0)
			return (alloc_prob2(buffer, line));
		check = cpy_str(line, temp);
		free(line);
		line = write_line(buffer, temp);
		free(temp);
		if (line == 0)
			return (alloc_prob2(buffer, line));
		if (*(line + line_len(line) - 1) == '\n')
			return (line);
		if (*(buffer + line_len(buffer)) == '\0')
			check = read_line(buffer, fd);
		if (check == -1 && *buffer == '\0')
		{
			alloc_prob(buffer);
			return (line);
		}
	}
	return (line);
}
