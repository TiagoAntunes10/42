/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:53:31 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/07 22:21:58 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*write_path(char *cmd, char *path)
{
	char	*path_cmd;
	char	*check;

	check = ft_substr(cmd, 0, 9);
	if (ft_strncmp(check, path, 9) != 0)
	{
		path_cmd = malloc(ft_strlen(cmd) + ft_strlen(path) + 1);
		if (path_cmd == NULL)
			return (NULL);
		ft_bzero(path_cmd, ft_strlen(cmd) + ft_strlen(path) + 1);
		ft_strlcat(path_cmd, path, ft_strlen(path) + 1);
		ft_strlcat(path_cmd, cmd, ft_strlen(path) + ft_strlen(cmd) + 2);
	}
	else
		path_cmd = cmd;
	free(check);
	return (path_cmd);
}

void	check_outfile(char **argv, int argc)
{
	if (access(argv[argc], F_OK) == 0)
	{
		if (unlink(argv[argc]) == -1)
		{
			perror(strerror(errno));
			exit(1);
		}
	}
}

void	handle_errors(void)
{
	perror(strerror(errno));
	exit(1);
}

int	free_array(char **array, char *path)
{
	int		i;
	char	*cmd;
	int		code;

	code = 1;
	cmd = ft_substr(array[0], 9, 4);
	if (ft_strncmp(cmd, "exit", 4) == 0)
		code = ft_atoi(array[1]);
	free(cmd);
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	free(path);
	return (code);
}

// int	write_file(char **argv, int argc)
// {
// 	int		fd[2];
// 	char	*line;

// 	fd[0] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
// 	fd[1] = open(argv[1], O_RDONLY);
// 	if (fd[0] == -1 || fd[1] == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	line = get_next_line(fd[1]);
// 	while (line != NULL)
// 	{
// 		write(fd[0], line, ft_strlen(line));
// 		free(line);
// 		line = get_next_line(fd[1]);
// 	}
// 	free(line);
// 	close(fd[0]);
// 	close(fd[1]);
// 	return (0);
// }

// int	write_one_cmd(char **argv, int argc)
// {
// 	int		fd[2];
// 	char	**cmd;

// 	fd[0] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
// 	fd[1] = open(argv[1], O_RDONLY);
// 	if (fd[0] == -1 || fd[1] == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	if (dup2(fd[0], 1) == -1 || dup2(fd[1], 0) == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	cmd = sep_args(argv[argc - 1], "/usr/bin/");
// 	if (execve(cmd[0], cmd, NULL) == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	return (0);
// }
