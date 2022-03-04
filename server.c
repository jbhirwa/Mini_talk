#include "minitalk.h"

t_data data;

void init_data(void)
{
	data.i = 0;
	data.bin = 0;
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		sig = 1;
	else
		sig = 0;
	data.bin = data.bin << 1 | sig;//adding transmitted binary digit to bin
	data.i++;
	if (data.i == 8)
	{
		if (data.bin != '\0')
			write(1, &data.bin, 1);
		else
			write(1, '\n', 1);
		init_data;
	}
}

int main()
{
	init_data();
	printf("pid: %d\n", getpid());
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	return(0);
}
