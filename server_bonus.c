/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:06:01 by sboetti           #+#    #+#             */
/*   Updated: 2023/05/05 11:35:47 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int sig, siginfo_t *siginfo, void *vouad)
{
	static int				c = 0;
	static int				i = 1;
	static pid_t			pid = 0;

	(void)vouad;
	if (!pid)
		pid = siginfo->si_pid;
	if (sig == SIGUSR1)
		c += 256;
	c = c >> 1;
	if (++i >= 9)
	{
		if (c == 0)
			pid = 0;
		else
			ft_printf("%c", c);
		i = 1;
		c = 0;
	}
	usleep(70);
	if (pid)
		kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	s;

	(void)argv;
	if (argc != 1)
		return (1);
	ft_printf("%d\n", getpid());
	s.sa_sigaction = &my_handler;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
	{
	}
	return (0);
}
