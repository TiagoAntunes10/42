/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:39:12 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/11 17:46:55 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof (int));
	i = 0;
	if (*range == 0)
		return (-1);
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}

/*#include <stdio.h>
int main(void)
{
	int	**range;
	int	*nb;
	int	min;
	int	max;
	int	i;
	int	j;

	range = &nb;
	min = -5;
	max = 5;
	i = ft_ultimate_range(range, min, max);
	j = 0;
	while (j < i)
	{
		printf("%d\n", (*range)[j]);
		j++;
	}
	printf("%d\n", i);
}*/
