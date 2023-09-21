/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:16:57 by aneiva-d          #+#    #+#             */
/*   Updated: 2023/09/03 13:01:17 by aneiva-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wrt(char ltr)
{
	write(1, &ltr, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb *= -1;
		wrt('-');
	}
	if (nb < 10)
	{
		wrt(nb + '0');
		return ;
	}
	else
	{
		ft_putnbr(nb / 10);
	}
	ft_putnbr(nb % 10);
}

/*int	main(void)
{
	ft_putnbr(-554);
	ft_putnbr(0);
	ft_putnbr(12445);
	ft_putnbr(-2147483648);
	return (0);
}*/
