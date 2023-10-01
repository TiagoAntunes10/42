/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:29:41 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/29 12:29:43 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
static int	nblen(int long n);
void		convert(int long n, char *str, int len);

char    *ft_itoa(int n)
{
	int long	nb;
	int			l;
	char		*str;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		l = nblen(nb);
		str = malloc(l + 2);
		str[0] = '-';
		convert(nb, str, l);
		str[l + 1] = '\0';
	}
	else
	{
		l = nblen(nb);
		str = malloc(l + 1);
		convert(nb, str, l - 1);
		str[l] = '\0';
	}
	if (str = 0)
		return (NULL);
	return (str);
}

static int	nblen(int long n)
{
	int	l;

	if (n / 10 == 0)
		return (1);
	l = 1;
	l += nblen(n / 10);
	return (l);
}

void	convert(int long n, char *str, int len)
{
	if (n / 10 == 0)
	{
		str[len] = (n % 10) + 48;
		return ;
	}
	convert((n / 10), str, (len - 1));
	str[len] = (n % 10) + 48;
	return ;
}

/*
#include <stdio.h>

int	main(void)
{
	int	n;

	n = -2147483648;
	printf("%s\n", ft_itoa(n));
}*/