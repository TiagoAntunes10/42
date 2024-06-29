#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	struct timeval	t_init;
	struct timeval	t_now;

	if (gettimeofday(&t_init, NULL) != 0)
		return (-1);
	printf("%ld\n", t_init.tv_usec);
	usleep(200000);
	if (gettimeofday(&t_now, NULL) != 0)
		return (-1);
	printf("%ld\n", t_now.tv_usec);
	printf("%ld\n", (t_now.tv_usec - t_init.tv_usec) / 1000);
}
