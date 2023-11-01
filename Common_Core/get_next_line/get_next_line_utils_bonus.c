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
	int	i;

	i = 0;
	check = read(fd, str, 1);
	if (check == -1 || check == 0)
		return (-1);
	while (*str != '\n' && *str != '\0')
	{
		check = read(fd, ++str, 1);
		i++;
		if (check == -1)
			return (-1);
	}
	return (i);
}
