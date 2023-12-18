/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:02:10 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 22:19:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_func(char **argv, int argc);
static void	child_func(char **argv, int argc);

int	main(int argc, char **argv)
{
	int	id;

	errno = 0;
	id = fork();
	if (id == -1)
	{
		ft_printf("Fork: ");
		perror(strerror(errno));
		exit(1);
	}
	else if (id == 0)
		child_func(argv, argc);
	else
		parent_func(argv, argc);
}

static void	parent_func(char **argv, int argc)
{
	// int		fd_out;
	// char	*str;

	wait(NULL);
	(void) argv;
	(void) argc;
	// str = get_next_line(fd[0]);
	// while (str != NULL)
	// {
	// 	if (write(fd_out, &str, ft_strlen(str)) == -1)
	// 	{
	// 		ft_printf("Write: ");
	// 		perror(strerror(errno));
	// 		free(str);
	// 		exit(1);
	// 	}
	// 	free(str);
	// 	str = get_next_line(fd[0]);
	// }
	// free(str);
	// close(fd_out);
	// close(fd[0]); 
}

static void	child_func(char **argv, int argc)
{
	int		fd_out;
	char	*cmd[2];

	fd_out = open(argv[argc - 1], O_WRONLY);
	if (fd_out == -1)
	{
		ft_printf("Open: ");
		perror(strerror(errno));
		exit(1);
	}
	if (dup2(fd_out, 1) == -1)
	{
		ft_printf("Dup: ");
		perror(strerror(errno));
		exit(1);
	}
	cmd[0] = "/usr/bin/";
	ft_strlcat(cmd[0], argv[2], ft_strlen(cmd[0]) + ft_strlen(argv[2]));
	ft_printf("%s", cmd[0]);
	cmd[1] = argv[2];
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		ft_printf("Execve: ");
		perror(strerror(errno));
		exit(1);
	}
}
