#include <stdio.h>

void    *memcpy(void *dest, void *src, unsigned int n)
{
    unsigned int    i;

    i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

/*
int main(void)
{
    char            *dest;
    char            *dest2;
    char            *src;
    unsigned int    n;
    char            c;
    char            k;
    int             arr[7];
    int             arr3[7];
    int             arr2[7] = {4, 5, 87, 2, 6, 2, 4};
    int             i;

    src = "fhbfdhdhfhbhoasj nhahb";
    dest = &c;
    dest2 = &k;
    n = 7;
    printf("ft_memcpy_str: %s\n", ft_memcpy(dest, src, sizeof(char) * n));
    printf("memcpy_str: %s\n", memcpy(dest2, src, sizeof(char) * n));
    arr = ft_memcpy(arr, arr2, sizeof(int) * n);
    arr3 = memcpy(arr, arr2, sizeof(int) * n);
    i = 0;
    printf("ft_memcpy_arr: ");
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf("memcpy_arr: ");
    while (i < n)
    {
        printf("%d ", arr3[i]);
        i++;
    }
    printf("\n");
}*/