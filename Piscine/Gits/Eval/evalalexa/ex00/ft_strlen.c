/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:55:43 by aneiva-d          #+#    #+#             */
/*   Updated: 2023/09/01 13:20:52 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		nb++;
		i++;
	}
	return (nb);
}

/*#include <stdio.h>
int	main(void)
{
	char	sntc[20] = "Wassup,\n gang!";

	printf("%d", ft_strlen(sntc));
	return (0);
}*/
