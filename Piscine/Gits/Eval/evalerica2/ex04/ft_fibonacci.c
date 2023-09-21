/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:40:47 by erferrei          #+#    #+#             */
/*   Updated: 2023/09/06 21:16:43 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	int	res;

	res = 0;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	res += ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_fibonacci(0));
	return 0;
}*/
