/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhabaguh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:52:18 by jhabaguh          #+#    #+#             */
/*   Updated: 2022/03/09 15:40:29 by jhabaguh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	reset_init(void)
{
	g_data.i = 0;
	g_data.bin = 0;
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		sig = 1;
	else
		sig = 0;
	g_data.bin = g_data.bin << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		if (g_data.bin != '\0')
			write(1, &g_data.bin, 1);
		else
			write(1, "\n", 1);
		reset_init();
	}
}

int	main(void)
{
	reset_init();
	printf("Pid: %d\n", getpid());
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		sleep(1);
	return (0);
}
