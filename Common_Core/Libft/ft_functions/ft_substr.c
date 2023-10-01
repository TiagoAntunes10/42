/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:52:36 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/29 08:52:49 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t  i;

    i = 0;
    str = malloc(len);
    if (str == 0)
        return (NULL);
    while (i < len)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    return (str);
}


/*#include <stdio.h>
int main (void)
{
    char    *s;
    
    s = "Hello, World";
    printf("%s\n", ft_substr(s, 7, 5));
}*/
