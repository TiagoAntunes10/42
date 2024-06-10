#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	struct timeval	time;
	struct timezone	tm_zone;

	if (gettimeofday(&time, &tm_zone) != 0)
		return (-1);
	printf("%ld\n", time.tv_sec);
	usleep(10000000);
	if (gettimeofday(&time, &tm_zone) != 0)
		return (-1);
	printf("%ld\n", time.tv_sec);
}
