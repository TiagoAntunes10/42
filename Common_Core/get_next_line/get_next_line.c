/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:10 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/31 13:55:13 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*alloc_prob(char *str);
static char	*alloc_prob2(char *str, char *str2);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	int			check;

	if (buffer == 0)
	{
		buffer = malloc(BUFFER_SIZE);
		if (buffer == 0)
			return (alloc_prob(buffer));
		check = write_line(buffer, fd);
		if (check == -1)
			return (alloc_prob(buffer));
	}
	check = 1;
	while (check > 0)
	{
		temp = buffer;
		buffer = line_len(buffer);
		line = write_line(temp, buffer - temp);
		if (line == 0)
			return (alloc_prob2(buffer, line));
		if (*buffer == '\0')
			check = write_line(buffer, fd);
	}
}

static char	*alloc_prob(char *str)
{
	free(str);
	return (NULL);
}

static char	*alloc_prob2(char *str, char *str2)
{
	free(str);
	free(str2);
	return (NULL);
}