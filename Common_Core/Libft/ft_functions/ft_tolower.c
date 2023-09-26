#include <stdio.h>
//#include <ctype.h>

int ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
        return (c - 32);
    else
        return (c);
}

/*
int main(void)
{
    char    c;

    c = 'F';
    printf("ft_tolower: %c\n", ft_tolower(c));
    printf("toulower: %c\n", tolower(c));
}*/