/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:17:53 by masoares          #+#    #+#             */
/*   Updated: 2023/09/10 10:29:46 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int main (int argc, char **argv)
{
	int		*tmp;
	int		**range;
	int		i;

	range = &tmp;
	i = 0;
	if (argc != 3)
		return(0);
	else
		ft_ultimate_range(range, atoi(argv[1]),atoi(argv[2]));
	
	while (i < (atoi(argv[2]) -atoi(argv[1]))) 
	{
		printf("%i\n",(*range)[i]);
		i++;
	}
}


int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if (max - min <= 0)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		*range = (int *)malloc ((max - min) * sizeof (int));
		if (*range == 0)
			return (-1);
		while (i < (max - min))
		{
			(*range)[i] = min + i;
			i++;
		}
		return (max - min);
	}
}
