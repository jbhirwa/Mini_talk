#include "minitalk.h"

void usage(void)
{
	printf("Usage instructions\n	Example: ./client <pid> \"your message\"\n");
}

int main(int argc, char **argv)
{
	char	*pid;
	char	*msg;

	if (argc == 3)
	{
		pid = argv[1];
		msg = argv[2];
		printf("%s %s\n", pid, msg);
	}
	else
		usage();
}
