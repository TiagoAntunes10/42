/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:02:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/14 18:05:02 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	fork_func(char **argv, int argc);
static void	parent_func(int *fd, char **argv, int argc);
static void	child_func(int *fd, char **argv);

int	main(int argc, char **argv)
{
	int	fd;

	errno = 0;
	if (argc < 5)
	{
		perror("Not enough arguments!");
		exit (1);
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
	return (fork_func(argv, argc));
}

static int	fork_func(char **argv, int argc)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle_errors();
	id = fork();
	if (id == -1)
		handle_errors();
	else if (id == 0)
		child_func(fd, argv);
	else
		parent_func(fd, argv, argc);
	return (0);
}

static void	parent_func(int *fd, char **argv, int argc)
{
	char	*path;
	char	**cmd;
	int		status;

	close(fd[1]);
	fd[1] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (fd[1] == -1)
		handle_errors();
	waitpid(-1, &status, WNOHANG);
	if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0) == -1)
		handle_errors();
	cmd = ft_split(argv[argc - 1], ' ');
	if (cmd == NULL)
		exit(1);
	path = write_path(cmd[0], "/usr/bin/");
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT)
			perror("command not found");
		else
			perror(strerror(errno));
		free_array(cmd, path);
		exit(127);
	}
}

static void	child_func(int *fd, char **argv)
{
	char	*path;
	char	**cmd;

	close(fd[0]);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		handle_errors();
	if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0))
		handle_errors();
	close(fd[1]);
	close(fd[0]);
	cmd = ft_split(argv[2], ' ');
	if (cmd == NULL)
		exit(1);
	path = write_path(cmd[0], "/usr/bin/");
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT)
			perror("command not found");
		else
			perror(strerror(errno));
		free_array(cmd, path);
		exit(1);
	}
}
