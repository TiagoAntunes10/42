/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plereno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:45:11 by plereno-          #+#    #+#             */
/*   Updated: 2023/09/01 10:04:40 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#include <stdio.h>
int	main(void)
{
	int	a;

	a = 24;
	printf("Antes de correr a funcao : %d\n", a);
	ft_ft(&a);
	printf("Depois de correr a funcao : %d\n", a);
}

