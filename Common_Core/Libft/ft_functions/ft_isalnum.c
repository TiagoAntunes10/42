/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_is'digiteric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:00:09 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/30 18:00:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <ctype.h>
//Confirmar se preciso de chamar a biblioteca aqui para correr as outras funções

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		return (c);
	else
		return (0);
}

/*int	main(void)
{
	char	c;

	c = '3';
	printf("ft_isalnum: %d\n", ft_isalnum(c));
	printf("isalnum: %d\n", isalnum(c));
}*/
