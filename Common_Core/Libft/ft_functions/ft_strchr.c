

char    *ft_strchr(char const *s, int c)
{
	char	*cs;

	cs = (char *) s;
    while (*cs != '\0')
    {
        if (*cs == c)
            return (cs);
        else
            cs++;
    }
    if (*cs == c)
        return (cs);
    else
        return ("\0");
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char    *s;
    char    c;

    s = "hfdb hnjnhdfb";
    c = 'n';
    printf("ft_strchr: %s\n", ft_strchr(s, c));
    printf("strchr: %s\n", strchr(s, c));
}*/