/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:56:13 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/30 21:56:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *ft_memchr(void const *s, int c, size_t n)
{
	unsigned int		i;
	char				*cs;

	cs = (char *) s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == c)
		{
			cs += i;
			return (cs);
		}
		else
			i++;
	}
	return ("\0");
}

/*
#include <string.h>
int main(void)
{
    char    *s;
    char    c;

    s = "hfdb hnjnhdfb";
    c = 'j';
    printf("ft_memchr_str: %s\n", (char *) ft_memchr(s, c, 10));
    printf("memchr_str: %s\n",  (char *) memchr(s, c, 10));
}*/
