/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:56:06 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/30 17:32:34 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);
void	swap(int *tab, int size, int ite);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 1;
	while (i <= (size / 2))
	{
		swap(tab, size, i);
		i++;
	}
}

void	swap(int *tab, int size, int ite)
{
	int	a;
	int	b;
	int	i;

	i = ite - 1;
	tab += i;
	a = *tab;
	b = 1;
	while (b <= (size - i - ite))
	{
		tab += 1;
		b++;
	}
	b = *tab;
	*tab = a;
	a = 1;
	while (a <= (size - i - ite))
	{
		tab -= 1;
		a++;
	}
	*tab = b;
}

/*int	main(void)
{
	int	array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	*tab;
	int	size;
	int	i;

	tab = &array[0];
	size = 9;
	i = 0;
	ft_rev_int_tab(tab, size);
	while (i < size)
	{
		printf("%d\n", *tab);
		tab += 1;
		i++;
	}
	}*/
