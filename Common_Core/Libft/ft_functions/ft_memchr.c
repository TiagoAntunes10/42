#include <stdio.h>
//#include <string.h>

void    *ft_memchr(void *s, int c, unsigned int n)
{
    unsigned int    i;
    char            *cs;

    cs = (char *) s;
    i = 0;
    while (i < n)
    {
        if (cs[i] == c)
        {
            s += i;
            return (s);
        }
        else
            i++;
    }
    return ("\0");
}

/*
int main(void)
{
    char    *s;
    char    c;
    int     arr[7] = {4, 6, 34, 7, 7, 43, 8};

    s = "hfdb hnjnhdfb";
    c = 'j';
    printf("ft_memchr_str: %s\n", ft_memchr(s, c, 10 * sizeof(char)));
    printf("memchr_str: %s\n", memchr(s, c, 10 * sizeof (char)));
    c = 7;
    printf("ft_memchr_arr: %d\n", ft_memchr(arr, c, 7 * sizeof(int)));
    printf("memchr_arr: %d\n", memchr(arr, c, 7 * sizeof(int)));
}*/