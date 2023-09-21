/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:16:55 by ade-alme          #+#    #+#             */
/*   Updated: 2023/09/09 16:19:46 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0')))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(void)
{
	printf("%d\n", ft_strncmp("Hellom", "Hellon", 6));
	printf("%d\n", ft_strncmp("bummer", "Gthi", 9));
	printf("%d\n", ft_strncmp("Jimpor", "Jimportu", 4));
}

