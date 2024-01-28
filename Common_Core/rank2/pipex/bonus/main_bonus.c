/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:02:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/27 22:51:03 by tialbert         ###   ########.fr       */
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

void	handle_fd(int *fd)
{
	if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0) == -1)
		handle_errors();
	close(fd[0]);
	close(fd[1]);
}

void	cmd_not_found(void)
{
	perror("command not found");
	errno = EKEYEXPIRED;
}
