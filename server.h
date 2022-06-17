/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:36:05 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 17:36:07 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

typedef struct s_receiver
{
	int	buff[8];
	int	count;
}	t_receiver;

t_receiver	g_receiver = {{0}, 0};

#endif
