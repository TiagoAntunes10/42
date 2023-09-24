#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int	ft_strlen(char *str);

int main(int argc, char **argv)
{
    int     file;
    int     out;
    char    c[1000];
    int     len;

    if (argc == 1)
    {
        write(1, "File name missing.\n", 19);
        return (0);
    }
    else if (argc > 2)
    {
        write(1, "Too many arguments.\n", 20);
        return(0);
    }
    file = open(argv[1], O_RDONLY);
    c[0] = '\0';
    out = read(file, &c, 1000);
    if (out == 0)
        write(1, "Cannot read file.\n", 18);
    else
    {
        len = ft_strlen(c);
        write(1, &c, len);
    }
    close(file);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		++l;
		++str;
	}
	return (l);
}