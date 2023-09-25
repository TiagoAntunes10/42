#include <stdio.h>

void    *memset(void *s, int c, unsigned int n)
{
    unsigned int    i;

    i = 0;
    while (i < n)
    {
        s = c;
        i++;
        s++;
    }
    return (s);
}

/*
int main(void)
{
    char            *str;
    unsigned int    n;
    char            c;
    int             arr[20];

    str = "fhbfdh dhfhbhoasj nhahb";
    c = '.';
    n = 7;
    printf("ft_memset: %s\n", ft_memset(str + 6, c, sizeof(char) * n)),
}*/
