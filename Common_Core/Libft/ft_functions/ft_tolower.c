

int ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
        return (c + 32);
    else
        return (c);
}


/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char    c;

    c = 'G';
    printf("ft_tolower: %c\n", ft_tolower(c));
    printf("toulower: %c\n", tolower(c));
}*/