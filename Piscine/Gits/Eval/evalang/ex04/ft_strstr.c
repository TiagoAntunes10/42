/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-vei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:23:30 by avaz-vei          #+#    #+#             */
/*   Updated: 2023/09/07 19:12:32 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (&str[0]);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j]
			&& (to_find[j] == str[i + j]))
		{
			j++;
		}
		if (!to_find[j])
			return (&str[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s",ft_strstr("teteste","teste"));
	printf("%s",strstr("teteste","teste"));
}	
	//These functions return a pointer to the 
	//beginning of the  located  sub‐
	//  string, or NULL if the substring is not found.}
