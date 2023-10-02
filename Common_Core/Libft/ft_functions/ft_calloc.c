#include <stdlib.h>

void    *ft_calloc(size_t nmem, size_t size)
{
    void        *arr;
    long int    n;

    if (nmem == 0 || size == 0)
        return (NULL);
    n = nmem * size;
    if (n > 2147483647)
        return (NULL);
    arr = malloc (nmem * size);
    return (arr);
}

/*
#include <stdio.h>
int main(void)
{
    int *arr;
    int *arr2;
    int nmem;
    int size;
    int i;

    nmem = 3;
    size = sizeof(int);
    arr = ft_calloc(nmem, size);
    arr2 = calloc(nmem, size);
    i = 0;
    while (i < nmem)
    {
        arr[i] = i + 3;
        arr2[i] = i + 3;
        i++;
    }
    i = 0;
    printf("ft_calloc: ");
    while (i < nmem)
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf("calloc: ");
    while (i < nmem)
    {
        printf("%d, ", arr2[i]);
        i++;
    }
    printf("\n");
}*/