#include "pipex.h"

char	**get_path(char **environ)
{
	char	**path;
	char	*temp;
	int		i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			temp = ft_substr(environ[i], 5, ft_strlen(environ[i]) - 5);
			path = ft_split(temp, ':');
			free(temp);
			break ;
		}
		i++;
	}
	return (path);
}
