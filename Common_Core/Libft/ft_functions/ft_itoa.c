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
static void	convert(int long n, char *str, int l);

char	*ft_itoa(int n)
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
		if (str == 0)
			return (NULL);
		str[0] = '-';
		convert(nb, str, l);
	}
	else
	{
		l = nblen(nb);
		str = malloc(l + 1);
		if (str == 0)
			return (NULL);
		convert(nb, str, (l - 1));
	}
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

static void	convert(int long n, char *str, int l)
{
	if (n / 10 == 0)
	{
		str[l] = (n % 10) + 48;
		str[l + 1] = '\0';
		return ;
	}
	convert((n / 10), str, l - 1);
	str[l] = (n % 10) + 48;
	str[l + 1] = '\0';
	return ;
}

/*
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <malloc.h>

int	main(void)
{
	int				n;
	char			*toa;
	struct mallinfo	info2;

	n = -2147483648;
	toa = ft_itoa(n);
	printf("ft_itoa '-2147483648': %s\n", toa);
	info2 = mallinfo();
	if (info2.keepcost != 0)
		printf("ft_itoa: Memory leaks -> %d bytes!\n", info2.keepcost);
}*/