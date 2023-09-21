/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:12:33 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 18:31:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		if (*(s1 + i) < *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		else if (*(s1 + i) > *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}


#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s1;
	char *s2;

	s1 = "bano";
	s2 = "banana";
	printf("strcmp: %i\n", strcmp(s1, s2));
	printf("ft_strcmp: %i\n", ft_strcmp(s1, s2));
}

