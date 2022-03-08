#include <string.h>

int	ft_atoi(const char *str)
{
	long	new;
	long	neg;
	size_t	c;

	c = 0;
	new = 0;
	neg = 1;
	while (str[c] == ' ' || (str[c] >= '\t' && str[c] <= '\r'))
	{
		c++;
	}
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-' )
		{
			neg = neg * -1;
		}
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		new = (str[c] - '0') + (new * 10);
		c++;
	}
	return (new * neg);
}
