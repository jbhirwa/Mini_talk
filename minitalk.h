#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

typedef struct	s_data
{
	int		i;
	char	bin;
}				t_data;


int	ft_putchar(char c);
int	ft_printf(const char *format, ...);
int	ConvPush_num(int num);
int	hex_num(unsigned int num, int base);
int	is_string(char *s);
int	ft_atoi(const char *str);
#endif
