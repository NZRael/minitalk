/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:06:01 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/20 17:08:00 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_server(void)
{
	char	*strpid;
	pid_t	pid;
	int		i;

	pid = getpid();
	i = 0;
	strpid = ft_itoa(pid);
	while (strpid[i])
		write(1, &strpid[i++], 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		return (1);
	ft_server();
	(void)argv;
	return (0);
}
