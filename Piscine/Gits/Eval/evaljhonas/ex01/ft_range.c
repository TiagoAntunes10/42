/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:44:02 by jburlama          #+#    #+#             */
/*   Updated: 2023/09/09 15:38:24 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	min;
	int	max;

	min = 50;
	max = 10;
	int	*ptr = ft_range(min, max);

	for (int i = 0; i < max - min; i++)
		printf("%i\n", ptr[i]);	
}


int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int	j;

	if (min >= max)
		return (0);
	array = (int *)malloc((max - min) * sizeof(int));
	i = min;
	j = 0;
	while (j < max - min)
	{
		array[j] = i;
		i++;
		j++;
	}
	return (array);
}
