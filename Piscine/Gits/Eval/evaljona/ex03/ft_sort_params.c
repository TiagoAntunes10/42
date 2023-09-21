/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:16:55 by jarcelin          #+#    #+#             */
/*   Updated: 2023/09/10 09:40:17 by jarcelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	strdifzero(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	comparar(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

void	imprimirargc(int argc, char **argv)
{
	int	i1;

	i1 = 1;
	while (i1 < argc)
	{
		strdifzero(argv[i1]);
		i1++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		i1;
	char	*x;

	i = 1;
	while (i < argc)
	{
		i1 = i + 1;
		while (i1 < argc)
		{
			if (comparar(argv[i], argv[i1]) > 0)
			{
				x = argv[i];
				argv[i] = argv[i1];
				argv[i1] = x;
			}
			i1++;
		}
		i++;
	}
	imprimirargc(argc, argv);
	return (0);
}
