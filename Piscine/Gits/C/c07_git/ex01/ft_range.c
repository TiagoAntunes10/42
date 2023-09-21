/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:20:34 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/11 17:45:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	j;

	if (min >= max)
	{
		return (NULL);
	}
	range = malloc((max - min) * sizeof(int));
	i = min;
	j = 0;
	while (i < max)
	{
		range[j] = i;
		i++;
		j++;
	}
	return (range);
}

/*#include <stdio.h>
int main(void)
{
	int	min;
	int	max;
	int	*range;
	int	i;

	min = -5;
	max = 5;
	range = ft_range(min, max);
	i = 0;
	while (i < (max - min))
	{
		printf("%d\n", range[i]);
		i++;
	}
}*/
