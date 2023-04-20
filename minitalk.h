/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:06:12 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/20 17:53:37 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
void	ft_putstr(char *str);
int	    ft_atoi(const char *str);
char	*ft_itoa(int n);

void	ft_bits(char *str, pid_t spid);
void	ft_client(char **argv);
int		ft_server(void);
void	check_client(int argc, char **argv);

#endif