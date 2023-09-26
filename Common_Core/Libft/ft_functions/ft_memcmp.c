#include <stdio.h>

int ft_memcmp(void *s1, void *s2, unsigned int n)
{
    unsigned int    i;
    char            *cs1;
    char            *cs2;

    if (n == 0)
        return (0);
    cs1 = (char *) s1;
    cs2 = (char *) s2;
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
int main(void)
{
    char    *s1;
    char    *s2;
    int     arr1[5] = {1, 2, 3, 4, 5};
    int     arr2[5] = {1, 3, 2, 4, 5};

    s1 = "hello world";
    s2 = "Hello World";
    printf("ft_memcmp_str: %d\n", ft_memcmp(s1, s2, 6));
    printf("memcmp_str: %d\n", memcmp(s1, s2, 6));
    printf("ft_memcmp_arr: %d\n", ft_memcmp(arr1, arr2, 4));
    printf("memcmp_arr: %d\n", memcmp(arr1, arr2, 4));
}*/