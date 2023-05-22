/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:38:49 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/22 16:55:02 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_bits(int pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(700);
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
	pid = ft_atoi(av[1]);
	msg = av[2];
	while (msg[i])
	{
		send_bits(pid, msg[i]);
		i++;
	}
	return (0);
}
