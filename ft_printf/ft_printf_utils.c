/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:36:59 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 17:37:01 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

static int	ft_put_pos_nbr(long long num, const char *alp, int base)
{
	char	arr[32];
	int		sum;
	int		i;

	if (num == 0)
	{
		write(1, &alp[0], 1);
		return (1);
	}
	sum = 0;
	while (num > 0)
	{
		arr[sum++] = alp[num % base];
		num /= base;
	}
	i = sum;
	while (--i >= 0)
		write(1, &arr[i], 1);
	return (sum);
}

int	ft_printnbr_base(long long num, const char *alp, int base)
{
	if (num < 0)
	{
		write(1, "-", 1);
		return (ft_put_pos_nbr(num * -1, alp, base) + 1);
	}
	return (ft_put_pos_nbr(num, alp, base));
}

int	ft_printpointer(unsigned long long num)
{
	char	arr[100];
	int		summa;
	int		i;

	write(1, "0x", 2);
	if (num == 0)
	{
		write(1, &"0123456789abcdef"[0], 1);
		return (3);
	}
	summa = 0;
	while (num > 0)
	{
		arr[summa++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	i = summa;
	while (--i >= 0)
		write(1, &arr[i], 1);
	return (summa + 2);
}
