/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:02:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/02 21:49:44 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_func(int *fd, char **argv, int argc);
static void	child_func(int *fd, char **argv, int argc);

int	main(int argc, char **argv)
{
	int	id;
	int	fd[2];

	errno = 0;
	if (access(argv[1], F_OK) == -1)
	{
		perror(strerror(errno));
		return (0);
	}
	if (pipe(fd) == -1)
	{
		ft_printf("Pipe: ");
		perror(strerror(errno));
		return (0);
	}
	id = fork();
	if (id == -1)
	{
		ft_printf("Fork: ");
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
	int		fd_out;
	char	**cmd;
	char	*line;

	close(fd[1]);
	if (access(argv[--argc], F_OK) == 0)
	{
		if (unlink(argv[argc]) == -1)
		{
			ft_printf("Unlink: ");
			perror(strerror(errno));
			return ;
		}
	}
	fd_out = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (fd_out == -1)
	{
		ft_printf("Open: ");
		perror(strerror(errno));
		return ;
	}
	wait(NULL);
	if (dup2(fd_out, 1) == -1 || dup2(fd[0], 0) == -1)
	{
		ft_printf("Dup: ");
		perror(strerror(errno));
		return ;
	}
	if (argc == 3)
	{
		line = get_next_line(0);
		while(line != NULL)
		{
			write(1, &line, ft_strlen(line));
			free(line);
			line = get_next_line(0);
		}
		free(line);
		return ;
	}
	cmd = sep_args(argv[argc - 1], "/usr/bin/");
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		ft_printf("Execve: ");
		perror(strerror(errno));
		return ;
	}
}

static void	child_func(int *fd, char **argv, int argc)
{
	char	**cmd;

	(void) argc;
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
	{
		ft_printf("Dup: ");
		perror(strerror(errno));
		exit(1);
	}
	close(fd[1]);
	cmd = sep_args_file(argv[2], argv[1], "/usr/bin/");
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		ft_printf("Execve: ");
		perror(strerror(errno));
		exit(1);
	}
}
