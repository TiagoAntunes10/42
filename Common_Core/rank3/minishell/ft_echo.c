/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:56:19 by tialbert          #+#    #+#             */
/*   Updated: 2024/10/17 21:34:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/minishell.h"

static void	write_echo(char **arr, int start)
{
		while (arr[start] != NULL)
		{
			if (printf("%s", arr[start++]) == -1)
				//TODO: Write error handling function with errno
		}
}

//TODO: Make ft_echo tests
void	ft_echo(t_tokens *token_lst, int *pipe)
{
	if (pipe != NULL)
	{
		if (dup2(1, pipe[1]) == -1)
			//TODO: Write error handling function with errno
	}
	if (ft_strncmp(token_lst->options[1], "-n", 2) == 0 && ft_strlen(token_lst->options[1]) == 2)
		write_echo(token_lst->options, 2);
	else
	{
		write_echo(token_lst->options, 1);
		if (printf("\n") == -1)
			//TODO: Write error handling function with errno
	}
	close(pipe[1]);
}
