/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:24:49 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/10 08:49:27 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index);

int	ft_fibonacci(int index)
{
	int	value;

	if (index > 1)
		value = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	else if (index == 1 || index == 2)
		value = 1;
	else if (index < 0)
		value = -1;
	else if (index == 3)
		value = 2;
	else
		value = 0;
	return (value);
}

/*#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_fibonacci(5));
}*/
