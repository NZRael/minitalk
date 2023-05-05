/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:06:09 by sboetti           #+#    #+#             */
/*   Updated: 2023/05/05 11:35:43 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	g_len;

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

void	charcounter(int sig)
{
	static size_t	count = 0;

	if (sig == SIGUSR1)
		count++;
	if (count == (g_len * 8) + 8)
		ft_printf("Signal Received !\n");
}

void	send_bit(int pid, char *argv)
{
	int	i;
	int	x;
	int	tmp;

	x = 0;
	while (argv[x])
	{
		tmp = argv[x];
		i = 8;
		while (i--)
		{
			usleep(70);
			if ((tmp & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			tmp = tmp >> 1;
			pause();
		}
		x++;
	}
}

void	endofmsg(int pid)
{
	int	i;

	i = 8;
	send_bit(pid, "\n");
	while (i--)
	{
		usleep(200);
		kill(pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	check_client(argc, argv);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	g_len = ft_strlen(argv[2]);
	signal(SIGUSR1, charcounter);
	send_bit(pid, argv[2]);
	endofmsg(ft_atoi(argv[1]));
	usleep(5);
	return (0);
}
