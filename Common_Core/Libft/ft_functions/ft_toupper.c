#include <stdio.h>
//#include <ctype.h>

int ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
        return (c - 32);
    else
        return (c);
}

/*
int main(void)
{
    char    c;

    c = 'g';
    printf("ft_toupper: %c\n", ft_toupper(c));
    printf("toupper: %c\n", toupper(c));
}*/