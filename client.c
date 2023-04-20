/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:06:09 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/20 17:53:41 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_checkbits(int bit, int spid)
{
	if (bit == 0)
	{
		if (kill(spid, SIGUSR1) == -1)
		{
			perror("kill");
			return ;
		}
	}
	else
	{
		if (kill(spid, SIGUSR2) == -1)
		{
			perror("kill");
			return ;
		}
	}
}

void	ft_bits(char *str, pid_t spid)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			bit = (str[i] >> j) & 1;
			ft_checkbits(bit, spid);
			j++;
			usleep(50);
		}
		i++;
	}
	return ;
}
// Récupérer le bit de poids faible du j-ème caractère de la chaîne message,
// en le considérant comme une suite de bits

void	ft_client(char **argv)
{
	char	*str;
	pid_t	server_pid;
	int		i;

	i = 0;
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, SIGUSR1) == -1)
	{
		perror("kill");
		return ;
	}
	str = ft_strdup(argv[2]);
	ft_bits(str, server_pid);
	return ;
}

int	main(int argc, char **argv)
{
	check_client(argc, argv);
	ft_client(argv);
	return (0);
}
