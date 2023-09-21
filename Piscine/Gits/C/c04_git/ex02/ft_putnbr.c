/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:49:58 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/09 11:42:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	write_nbr(long int nb);

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

/*int main(void)
{
	int	nb;

	nb = -2147483648;
	ft_putnbr(nb);
}*/
