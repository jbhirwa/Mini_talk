#include "minitalk.h"

t_data data;

void	reset_init(void)
{
	data.i = 0;
	data.bin = 0;
}

void	handler(int sig)
{

	if (sig == SIGUSR1)
		sig = 1
	else
		sig = 0;
	data.bin = data.bin << 1 | sig;
	data.i++;
	if (data.i == 8)
	{
		if (data.bin != '\0')
			write(1, &data.bin, 1);
		else
			write(1, '\n', 1);
		reset_init();
	}
}

int main()
{
	rest_init();
	printf("Pid: %d\n", getpid());
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while(1)
		sleep(1);
	return(0);
}
