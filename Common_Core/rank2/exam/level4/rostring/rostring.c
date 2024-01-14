#include <unistd.h>
#include <stdlib.h>

unsigned int	count_words(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str != 0)
	{
		while ((*str == ' ' || *str == '\t') && *str != 0)
			str++;
		while (*str != ' ' && *str != '\t' && *str != 0)
			str++;
		count++;
	}
	return (count);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str != 0 && *str != ' ' && *str != '\t')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_substr(char *str, unsigned int size)
{
	char	*sub;
	int		i;

	sub = malloc(size + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (*str != ' ' && *str != '\t' && *str != 0)
	{
		sub[i] = *str;
		str++;
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	**free_words(char **words, unsigned int n_words)
{
	unsigned int	i;

	i = 0;
	while (i < n_words)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char *str, unsigned int n_words)
{
	char			**words;
	unsigned int	len;
	unsigned int	i;

	words = malloc(sizeof(char *) * (n_words));
	if (words == NULL)
		return (NULL);
	i = 0;
	while (*str != 0)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		len = ft_strlen(str);
		words[i] = ft_substr(str, len);
		if (words[i] == NULL)
			return (free_words(words, i + 1));
		str += len;
		i++;
	}
	return (words);
}

int	main(int argc, char **argv)
{
	char			**words;
	unsigned int	i;
	unsigned int	n_words;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	n_words = count_words(argv[1]);
	words = ft_split(argv[1], n_words);
	if (words == NULL)
		return (0);
	i = 1;
	while (i < n_words)
	{
		write(1, words[i], ft_strlen(words[i]));
		write(1, " ", 1);
		i++;
	}
	write(1, words[0], ft_strlen(words[0]));
	free_words(words, n_words);
}
