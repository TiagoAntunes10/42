/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:01:31 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/01 11:01:41 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned int    i;
    char            *cs;

    i = 0;
    cs = (char *) s;
    while (i < n)
    {
        cs[i] = 0;
        i++;
    }
}

#include <string.h>

int main(void)
{
    char            *str;
    char            *str2;
    unsigned int    n;
    int             arr[7];
    int             arr2[7];
    unsigned int    i;

    str = "fhbfdh dhfhbhoasj nhahb";
    str2 = "fhbfdh dhfhbhoasj nhahb";
    n = 7;
    ft_bzero(str + 6, n);
    bzero(str2 + 6, n);
    printf("ft_bzero_str: %s\n", str);
    printf("bzero_str: %s\n", str2);
    ft_bzero(arr, n);
    bzero(arr2, n);
    i = 0;
    printf("ft_bzero_arr: ");
    while (i < n)
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("\nbzero_arr: ");
    i = 0;
    while (i < n)
    {
        printf("%d, ", arr2[i]);
        i++;
    }
    printf("\n");
}
