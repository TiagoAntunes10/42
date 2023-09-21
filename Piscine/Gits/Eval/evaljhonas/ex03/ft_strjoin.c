/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:07:13 by jburlama          #+#    #+#             */
/*   Updated: 2023/09/09 15:44:04 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(int size, char **strs, char *sep);

int	main(void)
{
	char	*strs[] = {"Hello,", "how", "are", "you", "?"};
	char	*sep = " ";

	char	*ptr = ft_strjoin(5, strs, sep);

	printf("%s\n", ptr);
}


char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		len_sum;
	int		i;
	int		j;
	int		k;

	len_sum = ft_strlen(size, strs, sep);
	ptr = malloc(len_sum + 1);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
		{
			ptr[k++] = strs[i][j];
		}
		j = -1;
		while (sep[++j] != '\0' && i != size -1)
		{
			ptr[k++] = sep[j];
		}
	}
	ptr[k] = '\0';
	return (ptr);
}

int	ft_strlen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len_sum;

	len_sum = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		len_sum += j;
		j = 0;
		if (i != size - 1)
		{
			while (sep[j] != '\0')
				j++;
			len_sum += j;
		}
		i++;
	}
	return (len_sum);
}
