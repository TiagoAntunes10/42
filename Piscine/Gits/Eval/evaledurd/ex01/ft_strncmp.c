/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:33:54 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 18:32:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((*(s1 + i) != '\0' || *(s2 + i) != '\0') && i < n)
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

	s1 = "b0nano";
	s2 = "banana";
	printf("strcmp: %i\n", strncmp(s1, s2, 2));
	printf("ft_strcmp: %i\n", ft_strncmp(s1, s2, 2));
}

