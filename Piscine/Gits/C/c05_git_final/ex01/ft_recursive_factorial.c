/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:10 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/10 11:28:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	int	value;

	if (nb > 1)
		value = nb * ft_recursive_factorial(nb - 1);
	else if (nb < 0)
		return (0);
	else
		value = 1;
	return (value);
}

/*#include <stdio.h>
int main(void)
{
    int nb;
    
    nb = 1;
    printf("%d\n", ft_recursive_factorial(nb));
}*/
