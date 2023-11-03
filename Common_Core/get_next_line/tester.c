#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("file", O_RDONLY);
	line = get_next_line(fd);
	while (*line != '\0')
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}
