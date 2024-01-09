/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:19:28 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/04 12:20:43 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	fork_func(char **argv, int argc);
static void	parent_func(int *fd, char **argv, int argc);
static void	child_func(int *fd, char **argv, int argc);

int	main(int argc, char **argv)
{
	errno = 0;
	if (access(argv[1], F_OK) == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	if (access(argv[--argc], F_OK) == 0)
	{
		if (unlink(argv[argc]) == -1)
		{
			perror(strerror(errno));
			return (0);
		}
	}
	if (argc == 2)
		return (write_file(argv, argc));
	else if (argc == 3)
		return (write_one_cmd(argv, argc));
	return (fork_func(argv, argc));
}

static int	fork_func(char **argv, int argc)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	id = fork();
	if (id == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	else if (id == 0)
		child_func(fd, argv, argc);
	else
		parent_func(fd, argv, argc);
	return (0);
}

static void	parent_func(int *fd, char **argv, int argc)
{
	char	**cmd;

	close(fd[1]);
	fd[1] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (fd[1] == -1)
	{
		perror(strerror(errno));
		return ;
	}
	wait(NULL);
	if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0) == -1)
	{
		perror(strerror(errno));
		return ;
	}
	cmd = sep_args(argv[argc - 1], "/usr/bin/");
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		perror(strerror(errno));
		return ;
	}
}

static void	child_func(int *fd, char **argv, int argc)
{
	char	**cmd;

	(void) argc;
	close(fd[0]);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
	{
		perror(strerror(errno));
		exit(1);
	}
	if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0))
	{
		perror(strerror(errno));
		exit(1);
	}
	close(fd[1]);
	close(fd[0]);
	cmd = sep_args(argv[2], "/usr/bin/");
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		perror(strerror(errno));
		exit(1);
	}
}
