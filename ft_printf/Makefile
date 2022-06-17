# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarthric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:36:30 by rarthric          #+#    #+#              #
#    Updated: 2022/03/11 17:36:32 by rarthric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c			ft_printf_utils.c

HEADER	=	ft_printf.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

FLAGS	=	-Werror -Wall -Wextra -I $(HEADER)

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@


clean	:
	rm -f $(OBJS) $(OBJS_B)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all
