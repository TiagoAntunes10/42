/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:34:57 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/30 17:40:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);
char	sort(int *tab, int size, int i);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sort(tab, size, i) == 'y')
			break ;
		i++;
	}
}

char	sort(int *tab, int size, int i)
{
	int	a;
	int	j;

	a = '\0';
	j = 0;
	while (j < (size - i - 1))
	{
		if (tab[j] > tab[j + 1])
		{
			a = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = a;
		}
		j++;
	}
	if (a == '\0')
		return ('y');
	else
		return ('n');
}

/*int	main(void)
{
	int	arr[10] = {7, 6, 3, 2, 1, 10, 4, 3, 1, 7};
	int	size;
	int	i;

	i = 0;
	size = 10;
	ft_sort_int_tab(arr, size);
	while (i < size)
	{
		printf("%d\n", arr[i]);
		i++;
	}	
}*/
