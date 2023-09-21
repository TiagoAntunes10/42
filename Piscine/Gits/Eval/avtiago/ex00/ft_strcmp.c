/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:36:30 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/07 17:36:36 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	a;
	int	b;

	while (*s1 != '\0' || *s2 != '\0')
	{
		a = *s1;
		b = *s2;
		if (a > b)
			return (a - b);
		else if (a < b)
			return (a - b);
		s1 += 1;
		s2 += 1;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "hello";
	s2 = "hello1";
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s1, s2));
}*/
