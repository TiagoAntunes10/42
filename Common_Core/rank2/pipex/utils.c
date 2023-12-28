/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:53:31 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/28 11:09:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**sep_args_file(char *cmd, char *file, char *path)
{
	char	**args;
	char	*path_cmd;
	char	*spa_file;

	spa_file = malloc(ft_strlen(file) + 2);
	spa_file[0] = ' ';
	ft_strlcat(spa_file, file, ft_strlen(file) + 2);
	path_cmd = malloc(ft_strlen(cmd) + ft_strlen(path)
				   + ft_strlen(spa_file) + 1);
	ft_strlcat(path_cmd, path, ft_strlen(path) + 1);
	ft_strlcat(path_cmd, cmd, ft_strlen(path) + ft_strlen(cmd) + 1);
	ft_strlcat(path_cmd, spa_file,
			ft_strlen(path_cmd) + ft_strlen(spa_file) + 1);
	args = ft_split(path_cmd, ' ');
	free(path_cmd);
	free(spa_file);
	return (args);
}

char	**sep_args(char *cmd, char *path)
{
	char	**args;
	char	*path_cmd;

	path_cmd = malloc(ft_strlen(cmd) + ft_strlen(path) + 1);
	ft_strlcat(path_cmd, path, ft_strlen(path) + 1);
	ft_strlcat(path_cmd, cmd, ft_strlen(path) + ft_strlen(cmd) + 1);
	args = ft_split(path_cmd, ' ');
	free(path_cmd);
	return (args);
}

