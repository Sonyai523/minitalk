/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:35:10 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 17:35:12 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int				i;
	long long int	summa;
	int				sign;

	i = 0;
	summa = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		summa = summa * 10 + str[i++] - '0';
	return (summa * sign);
}

void	err_msg(const char *msg)
{
	ft_printf(msg);
	exit(0);
}

void	send_str(int pid, const char *str)
{
	int		i;
	int		j;
	char	last;

	i = 0;
	last = '0';
	while (last)
	{
		j = 1 << 7;
		while (j > 0)
		{
			if (str[i] & j)
			{
				if (kill(pid, SIGUSR2) == -1)
					err_msg("PID ERROR\n");
			}
			else
				if (kill(pid, SIGUSR1) == -1)
					err_msg("PID ERROR\n");
			j = j >> 1;
			usleep(40);
		}
		last = str[i++];
	}
}

void	back_sig(int sig)
{
	(void)sig;
	ft_printf("Data received\n");
}

int	main(int args_c, char **args)
{
	if (args_c != 3)
		err_msg("usage: ./client [PID] [MESSAGE]\n");
	signal(SIGUSR1, back_sig);
	send_str(ft_atoi(args[1]), args[2]);
	usleep(1000);
}
