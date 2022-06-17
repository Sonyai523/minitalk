/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:35:55 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 17:35:57 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <zconf.h>
#include "server.h"

void	add_to_buf(int b, siginfo_t *info)
{
	char	c;
	int		i;

	(void)info;
	g_receiver.buff[g_receiver.count++] = b;
	if (g_receiver.count == 8)
	{
		c = 0;
		i = -1;
		while (++i < 8)
		{
			c *= 2;
			c += g_receiver.buff[i];
		}
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			c = '\n';
		}
		ft_printchr(c);
		g_receiver.count = 0;
	}
}

void	neg_sig(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	add_to_buf(0, info);
}

void	pos_sig(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	add_to_buf(1, info);
}

int	main(void)
{
	struct sigaction	neg;
	struct sigaction	pos;

	neg.sa_sigaction = neg_sig;
	neg.sa_flags = SA_SIGINFO;
	pos.sa_sigaction = pos_sig;
	pos.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &neg, NULL) != 0)
		ft_printf("sig error\n");
	if (sigaction(SIGUSR2, &pos, NULL) != 0)
		ft_printf("sig error\n");
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
}
