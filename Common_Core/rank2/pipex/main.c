#include "pipex.h"

int	main(int argc, char *argv)
{
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[argc - 1], O_ORDWR);
}
