//#include <stdio.h>
//#include <string.h>

int ft_strlen(char *str);

char    *ft_strrchr(char *s, int c)
{
    s += ft_strlen(s) - 1;
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        else
            s--;
    }
    if (*s == c)
        return (s);
    else
        return ("\0");
}

/*int main(void)
{
    char    *s;
    char    c;

    s = "hfdb hnjnhdfb";
    c = 'n';
    printf("ft_strrchr: %s\n", ft_strrchr(s, c));
    printf("strrchr: %s\n", strrchr(s, c));
}*/