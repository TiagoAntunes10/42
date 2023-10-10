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
static void	convert(int long n, char *str, int len);

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
		str[l + 1] = '\0';
	}
	else
	{
		l = nblen(nb);
		str = malloc(l + 1);
		if (str == 0)
			return (NULL);
		convert(nb, str, l - 1);
		str[l] = '\0';
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

static void	convert(int long n, char *str, int len)
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

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "libft.h"

int	main(void)
{
	int					n;
	char				*toa;
	struct mallinfo2	info2;

	n = 325;
	toa = ft_itoa(n);
	info2 = mallinfo2();
	printf("ft_itoa: '-2147483648': %s\n", toa);
	if (info2.smblks != 0)
		printf("ft_itoa: Memory leaks -> %ld bytes!\n", info2.smblks);
}