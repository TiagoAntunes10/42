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
static void	ft_bzero(void *s, size_t n);

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
		check = get_line(buffer, fd);
		if (check == -1 || check == 0)
			return (alloc_prob(buffer));
	}
	check = 1;
	line = malloc(1);
	if (line == 0)
			return (alloc_prob2(buffer, line));
	ft_bzero(line, 1);
	while (check > 0)
	{
		temp = malloc(line_len(line));
		if (temp == 0)
			return (alloc_prob2(buffer, line));
		check = cpy_str(line, temp);
		if (check > 0)
		{
			alloc_prob(temp);
			return (line);
		}
		free(line);
		line = write_line(buffer, temp, line_len(buffer) + line_len(temp));
		if (line == 0)
			return (alloc_prob2(buffer, line));
		if (*(buffer + line_len(buffer)) == '\0')
			check = get_line(buffer, fd);
		else
			buffer += line_len(buffer);
		if (check == -1)
		{
			alloc_prob(buffer);
			return (line);
		}
	}
	return (line);
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

static void	ft_bzero(void *s, size_t n)
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
