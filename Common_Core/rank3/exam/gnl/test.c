#include <stdio.h>
#include "gnl.h"
#include <fcntl.h>

int main(void)
{
	char	*line;
	int		fd;
	
	fd = open("gnl.c", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
