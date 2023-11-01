#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	char	*line2;
	int		fd;
	int		fd2;

	fd = open("file", O_RDONLY);
	fd2 = open("get_next_line.c", O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	while (line != NULL || line2 != NULL)
	{
		printf("%s", line);
		printf("%s", line2);
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
	}
	close(fd);
	close(fd2);
	free(line);
	free(line2);
}
