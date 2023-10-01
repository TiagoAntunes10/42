/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:08:17 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/30 22:08:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	if (n == 0)
		return (0);
	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		else
			i++;
	}
	return (0);
}

/*
#include <string.h>
int main(void)
{
    char    *s1;
    char    *s2;
    int     arr1[5] = {1, 2, 3, 4, 5};
    int     arr2[5] = {1, 1, 2, 3, 3};
	unsigned int	n;
	unsigned int	i;

	n = 11;
	i = 4;
    s1 = "hello world";
    s2 = "hello World";
    printf("ft_memcmp_str: %d\n", ft_memcmp(s1, s2, n));
    printf("memcmp_str: %d\n", memcmp(s1, s2, n));
    printf("ft_memcmp_arr: %d\n", ft_memcmp(arr1, arr2, i));
    printf("memcmp_arr: %d\n", memcmp(arr1, arr2, i));
}*/