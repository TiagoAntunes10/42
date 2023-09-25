#include <stdio.h>

void    ft_bzero(void *s, unsigned int n)
{
    unsigned int    i;

    i = 0;
    while (i < n)
    {
        *s = 0;
        i++;
        s++;
    }
    return (s);
}

/*
int main(void)
{
    char            *str;
    char            *str2;
    unsigned int    n;
    int             arr[7];
    int             arr2[7];
    int             i;

    str = "fhbfdh dhfhbhoasj nhahb";
    str2 = "fhbfdh dhfhbhoasj nhahb";
    n = 7;
    printf("ft_bzero_str: %s\n", ft_bzero(str + 6, sizeof(char) * n));
    printf("bzero_str: %s\n", bzero(str2 + 6, sizeof(char) * n));
    arr = ft_bzero(arr, sizeof(int) * n);
    arr2 = bzero(arr2, sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        printf("ft_bzero_arr: %d", arr[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while (i < n)
    {
        printf("bzero_arr: %d", arr2[i]);
        i++;
    }
    printf("\n");
}*/
