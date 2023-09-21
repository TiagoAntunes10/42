/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:26:30 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/09 09:29:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	**sort(int argc, char **str);
int		ft_strcmp(char *s1, char *s2);
char	**swap(char **argv, int i);

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	argv++;
	str = sort(argc, argv);
	i = 0;
	while (i < (argc - 1))
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char	**sort(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = "a";
	argc--;
	while (*str != '\0')
	{
		if (i == (argc - 1))
		{
			i = 0;
			argc--;
		}
		if (argc == 1)
			break ;
		j = ft_strcmp(argv[i], argv[i + 1]);
		if (j > 0)
			argv = swap(argv, i);
		i++;
	}
	return (argv);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;
	int	b;

	while (*s1 != '\0' || *s2 != '\0')
	{
		a = *s1;
		b = *s2;
		if (a > b)
			return (a - b);
		else if (a < b)
			return (a - b);
		s1 += 1;
		s2 += 1;
	}
	return (0);
}

char	**swap(char **argv, int i)
{
	char	*str;

	str = argv[i];
	argv[i] = argv[i + 1];
	argv[i + 1] = str;
	return (argv);
}
