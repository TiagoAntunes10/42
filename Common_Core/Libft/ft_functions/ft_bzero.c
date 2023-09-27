#include <stdio.h>
#include <string.h>

void    ft_bzero(void *s, unsigned int n)
{
    unsigned int    i;
    char            *cs;

    i = 0;
    cs = (char *) s;
    while (i < n)
    {
        *cs = 0;
        cs++;
        i++;
    }
}


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
}
