/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plereno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:33:34 by plereno-          #+#    #+#             */
/*   Updated: 2023/09/01 10:05:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

#include <stdio.h>
int	main(void)
{
	int	a;
	int	*a2;
	int	**a3;
	int	***a4;
	int	****a5;
	int	*****a6;
	int	******a7;
	int	*******a8;
	int	********a9;

	a = 24;
	a2 = &a;
	a3 = &a2;
	a4 = &a3;
	a5 = &a4;
	a6 = &a5;
	a7 = &a6;
	a8 = &a7;
	a9 = &a8;
	printf("Antes de correr a funcao : %d\n", a);
	ft_ultimate_ft(&a9);
	printf("Depois de correr a funcao : %d", a);
}
