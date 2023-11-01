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

char	*get_next_line(int fd)
{
	char	*line;
	int		check;

	line = malloc(100);
	if (line == 0)
		return (NULL);
	check = write_line(line, fd);
	if (check == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
