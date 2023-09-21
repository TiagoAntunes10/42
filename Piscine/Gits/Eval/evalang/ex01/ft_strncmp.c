/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-vei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:59:14 by avaz-vei          #+#    #+#             */
/*   Updated: 2023/09/07 19:04:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
		{
		}
		else if (s1[i] > s2[i])
		{
			return (1);
		}
		else
			return (-1);
		i++;
		if (s1[0] == '\0' && s2[0] == '\0')
		{
			return (0);
		}
		else if (s1[0] == '\0' && s2[0] != '\0')
		{
			return (-1);
		}
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char str1[] = "asdR";
	char str2[] = "asd";
	printf("%d",ft_strncmp(str1,str2,4));
	printf("%d",strncmp(str1,str2, 4));
}
