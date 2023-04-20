/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:36:18 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/20 17:14:33 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	chfr(int x, int i)
{
	if (x < 0)
		return (chfr(x * -1, 2));
	while (x >= 10)
	{
		x /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		x;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * chfr(n, 1) + 1);
	if (str == NULL)
		return (NULL);
	len = chfr(n, 1);
	x = n;
	str[len] = '\0';
	if (n < 0)
		x *= -1;
	while (--len >= 0)
	{
		str[len] = (x % 10) + 48;
		x /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	nb;

	i = 0;
	x = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * x);
}
