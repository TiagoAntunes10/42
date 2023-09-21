/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-vei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:12:28 by avaz-vei          #+#    #+#             */
/*   Updated: 2023/09/07 19:02:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char str1[] = "asddd ";
	char str2[] = "asddxxx";
	printf("%d",ft_strcmp(str1,str2));
	printf("%d",strcmp(str1,str2));
}
