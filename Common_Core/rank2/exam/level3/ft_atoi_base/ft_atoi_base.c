int	check_upper(const char *str)
{
	while (*str != 0)
	{
		if (*str >= 'A' && *str <= 'Z')
			return (1);
		str++;
	}
	return (0);
}

int	atoi_base(const char *str, char *base_ch, int str_base)
{
	int	i;
	int	num;

	num = 0;
	while (*str != 0)
	{
		i = 0;
		while (i < str_base)
		{
			if (*str == base_ch[i])
			{
				num = num * str_base + i;
				break ;
			}
			i++;
		}
		str++;
	}
	return (num);
}

int	check_neg(const char *str)
{
	if (*str == '-')
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char	*base_ch;
	int		num;

	if (check_upper(str) == 1)
		base_ch = "0123456789ABCDEF";
	else
		base_ch = "0123456789abcdef";
	num = atoi_base(str, base_ch, str_base);
	if (check_neg(str) == 1)
		return (num * -1);
	return (num);
}

#include <stdio.h>

int	main(void)
{
	char *str;

	str = "12FDB4";
	printf("Original base: %s\n", str);
	printf("Base 10: %d\n", ft_atoi_base(str, 16));
}