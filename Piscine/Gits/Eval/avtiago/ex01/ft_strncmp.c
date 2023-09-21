/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:36:54 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/07 17:36:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s1 < *s2)
			return (*s1 - *s2);
		else if (i == n)
			break ;
		s1 += 1;
		s2 += 1;
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*s1;
	char	*s2;
	unsigned int	n;

	s1 = "hello";
	s2 = "hello";
	n = 4;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
}*/
