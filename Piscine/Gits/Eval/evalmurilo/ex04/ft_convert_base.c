/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:16:17 by mde-souz          #+#    #+#             */
/*   Updated: 2023/09/11 19:25:54 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

long	ft_power(long nb, int power);

int		is_base_caracter(char c, char *base_from);

int		check_base(char *base);

int		get_base_index(char c, char *base);

long	ft_atoi(char *str, char *base_from)
{
	int		signal;
	long	num;
	int		i;

	signal = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * (-1);
		i++;
	}
	num = 0;
	while (is_base_caracter(str[i], base_from) == 1)
	{
		num = num * ft_strlen(base_from) + get_base_index(str[i], base_from);
		i++;
	}
	return (signal * num);
}

char	*convert(long nbr, char *base_to,
	char *nb_converted, int s_num_converted)
{
	int	base_index;
	int	s_base;
	int	i;

	s_base = ft_strlen(base_to);
	i = 0;
	if (nbr < 0)
	{
		nb_converted[i] = '-';
		s_num_converted--;
		nbr = -nbr;
		i++;
	}
	while (s_num_converted > 0)
	{
		base_index = (nbr / ft_power(s_base, s_num_converted - 1)) % s_base;
		nb_converted[i] = base_to[base_index];
		s_num_converted--;
		i++;
	}
	nb_converted[i] = '\0';
	return (nb_converted);
}

int	length_nb_converted(long nbr, char *base_to)
{
	int	length;
	int	s_base;

	length = 1 * (nbr > 0) + 2 * (nbr < 0);
	s_base = ft_strlen(base_to);
	if (nbr < 0)
		nbr = nbr * (nbr > 0) - nbr * (nbr < 0);
	while (nbr >= s_base)
	{
		length++;
		nbr /= s_base;
	}
	return (length);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;
	char	*nb_converted;
	int		s_num_converted;

	if (check_base(base_from) < 1 || check_base(base_to) < 1)
		return (0);
	num = ft_atoi(nbr, base_from);
	s_num_converted = length_nb_converted(num, base_to);
	nb_converted = (char *)malloc(sizeof(char) * s_num_converted + 1);
	if (!nb_converted)
		return (0);
	nb_converted = convert(num, base_to, nb_converted, s_num_converted);
	return (nb_converted);
}
#include <stdio.h>

int main(int argc,char **argv) {

	//char hexbase[] = "0123456789ABCDEF";
	//char binbase[] = "01";
	//char decbase[] = "0123456789";
	//char octbase[] = "poneyvif";
	(void)argc;

	printf("Sending number = %s\n", argv[1]);
	printf("base_from = %s\n", argv[2]);
	printf("base_to = %s\n", argv[3]);
	printf("Result = %s", ft_convert_base(argv[1], argv[2], argv[3]));
}
