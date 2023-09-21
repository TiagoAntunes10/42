/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:13:50 by masoares          #+#    #+#             */
/*   Updated: 2023/09/10 10:24:59 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char	*src);


int	main(int argc, char	**argv)
{
	if (argc == 2)
		printf("%s\n", ft_strdup(argv[1]));
}


int	ft_strlen(char	*src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*s;
	int		i;

	s = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
