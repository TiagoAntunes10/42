int	nb_len(int long nb)
{
	int	l;

	l = 0;
	if (nb < 0)
	{
		l = 1;
		nb *= -1;
	}
	if (nb / 10 == 0)
		return (1);
	l += 1;
	l += nb_len(nb / 10);
	return (l);
}

/*void	write_double(double nb, int dec)
{

}*/