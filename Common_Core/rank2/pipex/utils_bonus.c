/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:19:46 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/04 12:20:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**sep_args(char *cmd, char *path)
{
	char	**args;
	char	*path_cmd;

	if (ft_strncmp(ft_substr(cmd, 0, 9), path, 9) != 0)
	{
		path_cmd = malloc(ft_strlen(cmd) + ft_strlen(path) + 1);
		ft_bzero(path_cmd, ft_strlen(cmd) + ft_strlen(path) + 1);
		ft_strlcat(path_cmd, path, ft_strlen(path) + 1);
		ft_strlcat(path_cmd, cmd, ft_strlen(path) + ft_strlen(cmd) + 1);
		args = ft_split(path_cmd, ' ');
		free(path_cmd);
	}
	else
		args = ft_split(cmd, ' ');
	return (args);
}

int	write_file(char **argv, int argc)
{
	int		fd[2];
	char	*line;

	fd[0] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	fd[1] = open(argv[1], O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	line = get_next_line(fd[1]);
	while (line != NULL)
	{
		write(fd[0], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd[1]);
	}
	free(line);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	write_one_cmd(char **argv, int argc)
{
	int		fd[2];
	char	**cmd;

	fd[0] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	fd[1] = open(argv[1], O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	if (dup2(fd[0], 1) == -1 || dup2(fd[1], 0) == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	close(fd[0]);
	close(fd[1]);
	cmd = sep_args(argv[argc - 1], "/usr/bin/");
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	return (0);
}
