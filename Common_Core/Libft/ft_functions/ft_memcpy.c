#include <stdio.h>

void    *ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned int	i;
	char			*cdest;
	char const		*csrc;

	cdest = (char *) dest;
	csrc = (char const *) src;
	i = 0;
	if (csrc[i] != '\0')
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
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
    int             arr[5];
	int             arr3[5];
	int const       arr2[5] = {88, 5, 3, 6, 5};
    unsigned int    i;

    src = "fhbfdhdhf";
    n = 10;
    printf("ft_memcpy_str: %s\n", (char *) ft_memcpy(dest, src, n));
    printf("memcpy_str: %s\n", (char *) memcpy(dest2, src, n));
    n = 5;
    ft_memcpy(arr, arr2, n * sizeof(int));
    memcpy(arr3, arr2, n * sizeof(int));
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