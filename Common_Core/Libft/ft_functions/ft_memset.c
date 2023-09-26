#include <stdio.h>

void    *ft_memset(void *s, int c, unsigned int n)
{
    unsigned int    i;
    char            *cs;

    cs = (char *) s;
    i = 0;
    while (i < n)
    {
        cs[i] = c;
        i++;
        s++;
    }
    return (cs);
}

/*
int main(void)
{
    char            *str;
    char            *str2;
    unsigned int    n;
    char            c;
    int             arr[7];
    int             arr2[7];
    int             i;

    str = "fhbfdh dhfhbhoasj nhahb";
    str2 = "fhbfdh dhfhbhoasj nhahb";
    c = '.';
    n = 7;
    printf("ft_memset_str: %s\n", ft_memset(str + 6, c, sizeof(char) * n));
    printf("memset_str: %s\n", memset(str2 + 6, c, sizeof(char) * n));
    arr = ft_memset(arr, c, sizeof(int) * n);
    arr2 = memset(arr2, c, sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        printf("ft_memset_arr: %d", arr[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while (i < n)
    {
        printf("memset_arr: %d", arr2[i]);
        i++;
    }
    printf("\n");
}*/
