/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:01:46 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/14 17:21:01 by tialbert         ###   ########.fr       */
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
#include "./libraries/ft_printf.h"

extern char	**environ;

char	*write_path(char *cmd, char *path);
void	free_array(char **array, char *path);
void	handle_errors(void);
void	check_outfile(char **argv, int argc);
// int		write_file(char **argv, int argc);
// int		write_one_cmd(char **argv, int argc);
