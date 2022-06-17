/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:36:49 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 17:36:51 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printchr(int c);

int	ft_printstr(char *str);

int	ft_printnbr_base(long long n, const char *alp, int base);

int	ft_printpointer(unsigned long long num);

int	ft_printf(const char *str, ...);

#endif
