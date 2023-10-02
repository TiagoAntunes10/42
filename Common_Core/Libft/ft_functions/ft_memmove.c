#include <stdio.h>

void    *ft_memmove(void *dest, void const *src, size_t n)
{
    unsigned int    i;
    char            temp[n];
    char            *cdest;
    char            *csrc;

    cdest = (char *) dest;
    csrc = (char *) src;
    i = 0;
    while (i < n)
    {
        temp[i] = csrc[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        cdest[i] = temp[i];
        i++;
    }
    return (cdest);
}

/*
#include <string.h>
int main(void)
{
    char            dest[100];
    char            dest2[100];
    char            *src;
    unsigned int    n;
    int             arr[7];
    int             arr3[7];
    int             arr2[7] = {4, 5, 87, 2, 6, 2, 4};
	int				*arr4;
	int				*arr5;
	int				a;
	int				b;
    unsigned int	i;

	arr4 = &a;
	arr5 = &b;
    src = "fhbfdhdhfhbhoasj nhahb";
    n = 7;
    printf("ft_memmove_str: %s\n", (char *) ft_memmove(dest, src, sizeof(char) * n));
    printf("memmove_str: %s\n", (char *) memmove(dest2, src, sizeof(char) * n));
    arr4 = (int *) ft_memmove(arr, arr2, sizeof(int) * n);
    arr5 = (int *) memmove(arr3, arr2, sizeof(int) * n);
    i = 0;
    printf("ft_memmove_arr: ");
    while (i < n)
    {
        printf("%d ", arr4[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf("memmove_arr: ");
    while (i < n)
    {
        printf("%d ", arr5[i]);
        i++;
    }
    printf("\n");
}*/