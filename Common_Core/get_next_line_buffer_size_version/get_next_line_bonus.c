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

#include "get_next_line_bonus.h"

static char	*write_line(char **char_lake);
static void	forward_lake(char **char_lake);

char	*get_next_line(int fd)
{
	static char	*char_lake[MAX_FILES];
	char		*buffer;
	char		*line;
	int			check;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	check = read_file(buffer, &(char_lake[fd]), fd);
	free(buffer);
	if (check == -1)
		return(NULL);
	line = write_line(&(char_lake[fd]));
	forward_lake(&(char_lake[fd]));
	return (line);
}

static char	*write_line(char **char_lake)
{
	char	*line;
	char	*temp;
	int		i;
	int		len;

	if (*char_lake == NULL)
		return (NULL);
	temp = ft_strchr(*char_lake, '\n');
	len = ft_strlen(*char_lake) - ft_strlen(temp) + 1;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = (*char_lake)[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static void	forward_lake(char **char_lake)
{
	char	*temp;
	int		i;

	temp = ft_strchr(*char_lake, '\n');
	if (temp == NULL)
	{
		free(*char_lake);
		*char_lake = NULL;
		return ;
	}
	i = 0;
	temp++;
	while (temp[i] != '\0')
	{
		(*char_lake)[i] = temp[i];
		i++;
	}
	(*char_lake)[i] = 0;
}
