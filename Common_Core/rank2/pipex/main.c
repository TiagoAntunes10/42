/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:02:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/28 09:38:35 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	fork_func(char **argv, int argc, char **cmd_path);
static void	parent_func(int *fd, char **argv, int argc, char **cmd_path);
static void	child_func(int *fd, char **argv, char **cmd_path);

int	main(int argc, char **argv)
{
	int		fd;
	char	**cmd_path;

	errno = 0;
	if (argc < 5)
	{
		perror("Not enough arguments!");
		errno = EIO;
		exit (errno);
	}
	check_outfile(argv, --argc);
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		fd = open(argv[argc], O_WRONLY | O_CREAT, 0777);
		if (fd == -1)
			handle_errors();
		write(fd, "0\n", 2);
		perror(strerror(errno));
		exit(0);
	}
	cmd_path = get_path(environ);
	return (fork_func(argv, argc, cmd_path));
}

static int	fork_func(char **argv, int argc, char **cmd_path)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle_errors();
	id = fork();
	if (id == -1)
		handle_errors();
	else if (id == 0)
		child_func(fd, argv, cmd_path);
	else
		parent_func(fd, argv, argc, cmd_path);
	return (0);
}

static void	handle_fd(int *fd)
{
	if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0) == -1)
		handle_errors();
	close(fd[0]);
	close(fd[1]);
}

static void	parent_func(int *fd, char **argv, int argc, char **cmd_path)
{
	char	*path;
	char	**cmd;
	int		status;

	close(fd[1]);
	fd[1] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (fd[1] == -1)
		handle_errors();
	waitpid(-1, &status, WNOHANG);
	handle_fd(fd);
	cmd = split_check(argv[argc - 1]);
	if (cmd == NULL)
		exit(12);
	path = write_path(cmd[0], cmd_path);
	free_array(cmd_path, NULL);
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT || errno == EKEYEXPIRED)
			cmd_not_found();
		else
			perror(strerror(errno));
		free_array(cmd, path);
		exit(errno);
	}
}

static void	child_func(int *fd, char **argv, char **cmd_path)
{
	char	*path;
	char	**cmd;

	close(fd[0]);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		handle_errors();
	handle_fd(fd);
	cmd = split_check(argv[2]);
	if (cmd == NULL)
		exit(12);
	path = write_path(cmd[0], cmd_path);
	free_array(cmd_path, NULL);
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT || errno == EKEYEXPIRED)
			cmd_not_found();
		else
			perror(strerror(errno));
		free_array(cmd, path);
		exit(errno);
	}
}
