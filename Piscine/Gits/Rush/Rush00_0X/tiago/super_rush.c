/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:13:53 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/27 11:22:40 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	rush0X(int x, int y, int rush, char *c);
void	rush00(int x, int y, char *c);
void	rush01(int x, int y, char *c);
void	rush02(int x, int y, char *c);
void	rush03(int x, int y, char *c);
void	write_line00(int i, int x, char c1, char c2);
void	write_line01(int i, int x, char c1, char c2, char c3);

int	main(void)
{
	rush0X(5, 3, 2, "ABC");
	return (0);
}

/*x - length of the rectangule; 
 * y - height of the rectangule; 
 * rush - number of rush exercise (0, 1, 2, 3, 4); 
 * *c - write the characters in the order in which the
 * y are written in the exercise in quotations)*/

void	rush0X(int x, int y, int rush, char *c)
{
	if (rush == 0)
		rush00(x, y, c);
	else if (rush == 1 || rush == 4)
		rush01(x, y, c);
	else if (rush == 2)
		rush02(x, y, c);
	else if (rush == 3)
		rush03(x, y, c);
	else
		write(1, "Not a valid rush!\n", 19);
	return ;
}

void	rush00(int x, int y, char *c)
{
	int	i;
	int	j;
	char	c1;
	char	c2;
	char	c3;

	c1 = *c;
	c = c + 1;
	c2 = *c;
	c = c + 1;
	c3 = *c;
	j = 1;
	while (j <= y)
	{
		i = 1;
		if (j == 1 || j == y)
			write_line00(i, x, c1, c2);
		else
			write_line00(i, x, c3, c2);
		ft_putchar('\n');
		j++;
	}
	return ;
}

void	rush01(int x, int y, char *c)
{
	int	i;
	int	j;
	char	c1;
	char	c2;
	char	c3;

	c1 = *c;
	c = c + 1;
	c2 = *c;
	c = c + 1;
	c3 = *c;
	j = 1;
	while (j <= y)
	{
		i = 1;
		if (j == 1)
			write_line01(i, x, c1, c2, c3);
		else if (j == y)
			write_line01(i, x, c3, c2, c1);
		else
			write_line00(i, x, c2, ' ');
		ft_putchar('\n');
		j++;
	}
	return ;
}

void	rush02(int x, int y, char *c)
{
	int	i;
	int	j;
	char	c1;
	char	c2;
	char	c3;

	c1 = *c;
	c = c + 1;
	c2 = *c;
	c = c + 1;
	c3 = *c;
	j = 1;
	while (j <= y)
	{
		i = 1;
		if (j == 1)
			write_line00(i, x, c1, c2);
		else if (j == y)
			write_line00(i, x, c3, c2);
		else
			write_line00(i, x, c2, ' ');
		ft_putchar('\n');
		j++;
	}
	return ;
}

void	rush03(int x, int y, char *c)
{
	int	i;
	int	j;
	char	c1;
	char	c2;
	char	c3;
	
	c1 = *c;
	c = c + 1;
	c2 = *c;
	c = c + 1;
	c3 = *c;
	j = 1;
	while (j <= y)
	{
		i = 1;
		if (j == 1)
			write_line01(i, x, c1, c2, c3);
		else if (j == y)
			write_line01(i, x, c1, c2, c3);
		else
			write_line00(i, x, c2, ' ');
		ft_putchar('\n');
		j++;
	}
	return ;
}

void	write_line00(int i, int x, char c1, char c2)
{
	while (i <= x)
	{
		if (i == 1 || i == x)
			ft_putchar(c1);
		else
			ft_putchar(c2);
		i++;
	}
}

void	write_line01(int i, int x, char c1, char c2, char c3)
{
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(c1);
		else if (i == x)
			ft_putchar(c3);
		else
			ft_putchar(c2);
		i++;
	}
}

