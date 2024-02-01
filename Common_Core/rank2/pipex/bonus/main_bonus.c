/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:02:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 10:54:24 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		limiter(argv, argc);
	else
		multi(argv, argc);
}

void	handle_fd(int *fd, int mode, char **cmd_path)
{
	if (mode == 0)
	{
		if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			handle_errors(cmd_path, 0);
		}
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		handle_errors(cmd_path, 0);
	}
}

void	cmd_not_found(char *cmd)
{
	ft_printf("command not found: %s\n", cmd);
	errno = EKEYEXPIRED;
}
