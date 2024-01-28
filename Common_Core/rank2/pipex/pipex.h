/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:01:46 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/27 22:47:23 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "./libft/ft_printf.h"

extern char	**environ;

char	*write_path(char *cmd, char **path);
void	free_array(char **array, char *path);
void	handle_errors(void);
void	cmd_not_found(void);
void	check_outfile(char **argv, int argc);
char	**split_check(char *cmd);
char	**get_path(char **environ);
// int		write_file(char **argv, int argc);
// int		write_one_cmd(char **argv, int argc);
