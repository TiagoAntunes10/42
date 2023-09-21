/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:15:28 by marvin            #+#    #+#             */
/*   Updated: 2023/09/11 19:16:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*str;
	int	i;
	int	length;

	if (min >= max)
		return (0);
	length = max - min;
	str = (int *)malloc(sizeof(int) * (max - min));
	if (!str)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		str[i] = min + i;
		i++;
	}
	return (str);
}
#include<stdio.h>
int	main(int argc, char **argv)
{
	int	i = 0;
	(void) argc;
	int *mat;

	mat = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d\n", mat[i]);
		i++;
	}
	if (mat == 0)
			printf("Nulo %p",mat);
	else
		printf("Endereco %p\n",mat);
	return (0);
}
