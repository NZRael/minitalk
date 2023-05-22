/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:20:43 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/22 12:56:39 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits(int sig)
{
	static int		c = 0;
	static int		bit = 7;

	if (sig == SIGUSR1)
		c += 1 << bit;
	bit--;
	if (bit == -1)
	{
		ft_printf("%c", c);
		bit = 7;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sig.sa_handler = get_bits;
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
