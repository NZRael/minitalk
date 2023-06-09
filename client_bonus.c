/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:59:53 by sboetti           #+#    #+#             */
/*   Updated: 2023/05/24 11:28:25 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_global = 0;

void	check_client(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(-1);
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			i++;
		else
			exit(-1);
	}
	return ;
}

void	msg_send(int sig)
{
	(void)sig;
	ft_printf("Signal send.\n");
}

void	add_global(int signum)
{
	(void)signum;
	g_global++;
}

void	send_bits(int pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		g_global = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_global == 0)
			;
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	check_client(ac, av);
	i = 0;
	signal(SIGUSR1, msg_send);
	pid = ft_atoi(av[1]);
	msg = av[2];
	signal(SIGUSR2, &add_global);
	while (msg[i])
	{
		send_bits(pid, msg[i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
