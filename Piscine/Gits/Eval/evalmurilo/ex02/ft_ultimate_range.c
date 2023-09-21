/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:35:46 by mde-souz          #+#    #+#             */
/*   Updated: 2023/09/11 19:21:34 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*str;
	int	length;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	length = max - min;
	str = (int *)malloc(sizeof(int) * (length));
	if (!str)
		return (-1);
	i = 0;
	while (i < (length))
	{
		str[i] = min + i;
		i++;
	}
	*range = str;
	return (length);
}
#include<stdio.h>
int main(int argc, char **argv)
{
	int	**arr;
	int	*arr2;
	int	i = 0;
	(void) argc;
	arr = &arr2;
	printf("Range: %d \n", ft_ultimate_range(arr, atoi(argv[1]), atoi(argv[2])));

	while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d ", arr2[i]);
		i++;
	}
	if (arr2 == 0)
			printf("Nulo %p",arr2);
	else
		printf("\nEndereco %p\n",arr2);
	return (0);
	return 0;
}
