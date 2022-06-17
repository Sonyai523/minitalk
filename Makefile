# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarthric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:34:59 by rarthric          #+#    #+#              #
#    Updated: 2022/03/11 17:35:02 by rarthric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME	=	client

S_NAME	=	server

C_SRCS	=	client.c	ft_printf/libftprintf.a

S_SRCS	=	server.c	ft_printf/libftprintf.a

FLAGS	=	-Werror -Wextra -Wall

.PHONY	:	all clean fclean re bonus

all		:	client_c server_c

client_c	:	printf_c	${C_SRCS}
	gcc ${FLAGS} ${C_SRCS} -o ${C_NAME}

server_c	:	printf_c	${S_SRCS}
	gcc ${FLAGS} ${S_SRCS} -o ${S_NAME}

printf_c	:
	make -C ft_printf

clean		:
	make -C ft_printf clean

fclean		:
	make -C ft_printf fclean
	rm -f ${S_NAME}
	rm -f ${C_NAME}

re			:	fclean	all

bonus		:	all
