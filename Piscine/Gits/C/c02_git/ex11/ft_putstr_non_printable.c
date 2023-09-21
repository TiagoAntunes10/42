/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:04:21 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/06 17:34:27 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	write_hex(int a);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i + 1] != '\0')
	{
		if (str[i] <= 31)
		{
			write(1, "\\", 1);
			write_hex(str[i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

void	write_hex(int a)
{
	if (a < 10)
	{
		a += 48;
		write(1, "0", 1);
		write(1, &a, 1);
	}
	else if (a >= 10 && a < 16)
	{
		a += 87;
		write(1, "0", 1);
		write(1, &a, 1);
	}
	else if (a >= 16 && a < 26)
	{
		a += 32;
		write(1, "1", 1);
		write(1, &a, 1);
	}
	else
	{
		a += 71;
		write(1, "1", 1);
		write(1, &a, 1);
	}
}

/*int	main(void)
{
	char	str[30] = "Coucou\n\t\0tu vas bien ?";

	ft_putstr_non_printable(str);
}*/
