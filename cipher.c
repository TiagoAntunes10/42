#include <unistd.h>

void	change(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm'))
		{
			i = *str + 13;
			write(1, &i, 1);
		}
		else if ((*str >= 'N' && *str <= 'Z') || (*str >= 'n' && *str <= 'z'))
		{
			i = *str - 13;
			write(1, &i, 1);
		}
		else if (*str >= '0' && *str <= '9')
		{
			i = *str - 5;
			write(1, &i, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	char	str[500] = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe \
rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe \
gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl n \
cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal \
nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur \
cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf: \
Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl \
hccre tenivgl ureb";

	change(str);
}