#include <stdlib.h>
#include <stdio.h>

int		count_words(char *str, char *charset);
int		ft_strlen(char *str, char *charset);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**words;
	int		len;
	int		i;

	count = count_words(str, charset);
	words = malloc((count + 1) * sizeof(char *));
	i = 0;
	while (*str != '\0')
	{
		len = ft_strlen(str, charset);
		if (len == 0)
		{
			str += 1;
			continue ;
		}
		words[i] = malloc(len + 1);
		words[i] = ft_strncpy(words[i], str, len);
		str += len;
		i++;
	}
	return (words);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (charset[j] != '\0' && str[i] != charset[j])
		{
			j++;
			if (charset[j] == '\0')
			{
				i++;
				j = 0;
			}
		}
		count++;
		while (charset[j] == str[i])
			i++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	l;
	int	i;

	l = 0;
	while (*str != '\0')
	{
		i = 0;
		while (*str != charset[i] && charset[i] != '\0')
			i++;
		if (*str == charset[i])
			break ;
		l++;
		str++;
	}
	return (l);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(int argc, char **argv)
{
	char	**words;
	int		i;

	if (argc != 3)
		return (0);
	words = ft_split(argv[1], argv[2]);
	i = 0;
	while (words[i][0] != '\0')
	{
		printf("%s\n", words[i]);
		i++;
	}
}
