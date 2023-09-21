/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:31:15 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/03 17:17:58 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rush01(char *top, char *bottom);
void	input_separation(char *input, char *row, int pos);
int		errors(char *input);
void	write_matrix(char column[4][4]);
char	**matrix(char *conditions);

int	main(int argc, char **argv)
{
	char	*top;
	char	*bottom;
	char	*left;
	char	*right;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		(void) **argv;
	}
	top = (char *) malloc((errors(argv[1]) / 4 + 1));
	bottom = (char *) malloc((errors(argv[1]) / 4 + 1));
	left = (char *) malloc((errors(argv[1]) / 4 + 1));
	right = (char *) malloc((errors(argv[1]) / 4 + 1));
	input_separation(argv[1], top, 0);
	input_separation(argv[1], bottom, 1);
	input_separation(argv[1], left, 2);
	input_separation(argv[1], right, 3);
	rush01(top, bottom);
}

void	input_separation(char *input, char *row, int pos)
{
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		if (pos == 0 && i == 1)
			j = 0;
		else if (pos == 1 && i == 1)
			j = 8;
		else if (pos == 2 && i == 1)
			j = 16;
		else if (pos == 3 && i == 1)
			j = 24;
		*row = input[j];
		row += 1;
		j += 2;
		i++;
	}
	*row = '\0';
}

int	errors(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if (i == 0 && input[i] >= '1' && input[i] <= '9')
			count += 1;
		else if (i > 0 && input[i] >= '1' 
			&& input[i] <= '9' && input[i - 1] == ' ')
			count += 1;
		else if (input[i] != ' ' && input[i] < '1' && input[i] > '9')
			write(1, "Error\n", 6);
		else if (i > 31)
			write(1, "Error\n", 6);
		i++;
	}
	return (count);
}
