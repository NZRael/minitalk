/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:49:58 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/22 12:57:54 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits_bonus(int sig, siginfo_t *info, void *oldact)
{
	static int	bit = 7;
	static int	c = 0;

	(void)oldact;
	if (sig == SIGUSR1)
		c += 1 << bit;
	bit--;
	if (bit == -1)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		else
			ft_printf("%c", c);
		bit = 7;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = get_bits_bonus;
	sig.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
