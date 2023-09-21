/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:05:10 by jburlama          #+#    #+#             */
/*   Updated: 2023/09/09 15:42:55 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	min;
	int	max;
	int	size;
	int	*ptr;

	min = 5;
	max = 10;
	size = ft_ultimate_range(&ptr, min, max);
	printf("the funtion returns: %i\n", size);

	for (int i = 0; i < size; i++)
		printf("%i\n", ptr[i]);

	printf("%p\n", ptr);
}


int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (-1);
	}
	size = max - min;
	i = 0;
	*range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
