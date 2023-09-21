/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:53:17 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/03 17:28:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	rush01(char *top, char *bottom);
char	**matrix(char *conditions);
void	write_matrix(char **column);

void	rush01(char *top, char *bottom)
{
	char	**column;
	int		i;

	i = 0;
	while (top[i] != '\0')
	{
		if (top [i] == bottom[i] && top[i] != '2')
		{
			write(1, "Error\n", 6);
			break ;
		}
		i++;
	}
	column = matrix(top);
	write_matrix(column);
}

char	**matrix(char *conditions)
{
	int		i;
	int		j;
	char	**column;

	i = 0;
	while (conditions[i] != '\0')
	{
		j = 4;
		while (j >= 1)
		{
			if (conditions[i] == '4')
			{
				column[j - 1][i] = j + 48;
			}
			else if (conditions[i] == '3')
			{
				if (j <= 1)
					column[j + 2][i] = j + 48;
				else
					column[j - 2][i] = j + 48;
			}
			else if (conditions[i] == '2')
			{
				
				if (j <= 2)
					column[j + 1][i] = j + 48;
				else
					column[j - 3][i] = j + 48;
			}
			else if (conditions[i] == '1')
			{
				if (j == 3)
					column[j - 2][i] = j + 48;
				else if (j == 2)
					column[j][i] = j + 48;
				else if (j == 1)
					column[j + 2][i] = j + 48;
				else
					column[j - 4][i] = j + 48;
			}
			j--;
		}
		i++;
	}
	return (column);
}

void	write_matrix(char **column)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &column[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		printf("\n");
		i++;
	}
}
