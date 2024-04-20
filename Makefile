# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 03:42:54 by kait-baa          #+#    #+#              #
#    Updated: 2023/11/24 04:48:49 by kait-baa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_putnbr_base.c ft_putstr.c ft_putchar.c ft_puthexa.c ft_putstr_p.c ft_putnbr.c ft_putaddress.c ft_printf.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

%.o:			%.c
	$(CC) $(CFLAGS) -c $<
	ar -rcs $(NAME) $@
