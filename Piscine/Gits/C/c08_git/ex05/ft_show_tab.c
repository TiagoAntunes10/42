/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:21:59 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/13 19:34:32 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	write_nbr(long int nbr);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (*par[i].str != '0')
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str = str + 1;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	long int	j;

	j = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		j *= -1;
	}
	write_nbr(j);
	write(1, "\n", 1);
	return ;
}

void	write_nbr(long int nb)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (div == 0)
	{
		mod += 48;
		write(1, &mod, 1);
		return ;
	}
	else
		write_nbr(div);
	mod += 48;
	write(1, &mod, 1);
	return ;
}

/*int main(int argc, char **argv)
{
	t_stock_str	*strs;

	argv += 1;
	strs = ft_strs_to_tab(argc - 1, argv);
	ft_show_tab(strs);
}*/
