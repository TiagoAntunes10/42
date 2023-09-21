/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:18:08 by masoares          #+#    #+#             */
/*   Updated: 2023/09/10 10:27:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	main(int argc, char	**argv)
{
	int		i;
	int		*c;

	i = 0;
	if (argc == 3)
	{
		c = ft_range (atoi(argv[1]), atoi(argv[2]));
		while (i < atoi(argv[2]) - atoi(argv[1]))
		{
			printf("%d\n", c[i]);
			i++;
		}
	}
}

int	*ft_range(int min, int max)
{
	int		*s;
	int		i;

	if (min >= max)
		return (NULL);
	s = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while ((min + i) < max)
	{
		s[i] = min + i;
		i++;
	}
	return (s);
}
