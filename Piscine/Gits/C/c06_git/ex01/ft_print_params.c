/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:21:54 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/09 09:23:05 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	while (i < argc)
	{
		j = 0;
		str = argv[i];
		while (str[j] != '\0')
		{
			write(1, &str[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
