/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:36:39 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 17:36:41 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	check_perc(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || \
	c == 'd' || c == 'i' || c == 'u' || c == 'x' || \
	c == 'X' || c == '%');
}

int	print_arg(char d, va_list *ptr)
{
	if (d == 'c')
		return (ft_printchr(va_arg(*ptr, int)));
	else if (d == 's')
		return (ft_printstr(va_arg(*ptr, char *)));
	else if (d == 'd' || d == 'i')
		return (ft_printnbr_base(va_arg(*ptr, int), "0123456789", 10));
	else if (d == 'u')
		return (ft_printnbr_base(va_arg(*ptr, unsigned int), "0123456789", 10));
	else if (d == 'x')
		return (ft_printnbr_base(va_arg(*ptr, unsigned int), \
		"0123456789abcdef", 16));
	else if (d == 'X')
		return (ft_printnbr_base(va_arg(*ptr, unsigned int), \
		"0123456789ABCDEF", 16));
	else if (d == '%')
		return (ft_printchr('%'));
	else if (d == 'p')
		return (ft_printpointer(va_arg(*ptr, unsigned long long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		sum;

	va_start(ptr, str);
	sum = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (check_perc(*(str + 1)))
			{
				sum += print_arg(*(str + 1), &ptr);
				str++;
			}
		}
		else
		{
			write(1, str, 1);
			sum += 1;
		}
		if (*str)
			str++;
	}
	return (sum);
}
