/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:18:17 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/27 10:07:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	write_three(char i, char j, char k);

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i;
		j++;
		while (j <= '8')
		{
			k = j;
			k++;
			while (k <= '9')
			{
				write_three(i, j, k);
				if (i != '7')
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	write_three(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	return ;
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
