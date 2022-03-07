#include "minitalk.h"

void	char_to_bin(char c, pid_t pid)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if (c >> i & 1)
			kill(SIGUSR1, pid);
		else
			kill(SIGUSR2), pid;
		usleep(100);
		i--;
	}
}

void	str_to_char(char *str, pid_t pid)
{ 
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		char_to_bin(str[1], pid);
		i++;
	}
	char_to_bin(str[1], pid);
}

void usage(void)
{
	printf("Usage instructions\n	Example: ./client <pid> \"your message\"\n");
}

int main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
		usage();
	msg = argv[2];
	pid = argv[1];//ascii
	str_to_char(msg, pid);
}
