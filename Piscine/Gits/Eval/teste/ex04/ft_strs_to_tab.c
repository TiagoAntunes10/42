/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:25:23 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/13 19:31:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strs;
	int			i;

	strs = malloc((ac + 1) * sizeof(t_stock_str));
	i = 0;
	while (i < ac)
	{
		strs[i].size = ft_strlen(av[i]);
		strs[i].str = malloc(strs[i].size + 1);
		if (strs[i].str == 0)
		{
			strs[i].str = "\0";
			return (strs);
		}
		strs[i].str = ft_strcpy(strs[i].str, av[i]);
		strs[i].copy = malloc(strs[i].size + 1);
		strs[i].copy = ft_strcpy(strs[i].copy, strs[i].str);
		i++;
	}
	strs[i].size = 0;
	strs[i].str = malloc(1);
	strs[i].str = "0";
	return (strs);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
