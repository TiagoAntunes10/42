#include "gnl.h"

char	*ft_strchr(char *str, int c)
{
	while (*str != 0)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (*(str++) != 0)
		l++;
	return (l);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src != 0)
		*(dst++) = *(src++);
	*dst = 0;
}

char	*ft_strdup(char *str)
{
	char	*dup;

	dup = malloc(ft_strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, str);
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy(join + ft_strlen(s1), s2);
	free(s1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*line;
	char	*newline;
	int		to_cpy;
	int		read_size;

	line = ft_strdup(buf);
	while ((newline = ft_strchr(line, '\n')) == NULL && (read_size = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_size] = 0;
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (newline != NULL)
	{
		to_cpy = newline - line + 1;
		ft_strcpy(buf, newline + 1);
	}
	else
	{
		to_cpy = ft_strlen(line);
		buf[0] = 0;
	}
	line[to_cpy] = 0;
	return (line);
}
