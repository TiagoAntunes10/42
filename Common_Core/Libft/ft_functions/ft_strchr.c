#include <stdio.h>
//#include <string.h>

char    *ft_strchr(char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        else
            s++;
    }
    if (*s == c)
        return (s);
    else
        return ("\0");
}

/*
int main(void)
{
    char    *s;
    char    c;

    s = "hfdb hnjnhdfb";
    c = 'j';
    printf("ft_strchr: %s\n", ft_strchr(s, c));
    printf("strchr: %s\n", strchr(s, c));
}*/