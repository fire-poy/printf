# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 14:58:24 by mpons             #+#    #+#              #
#    Updated: 2021/11/19 18:02:14 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c\
			  ft_aux.c\
			  ft_put_address.c\

NAME		= libftprintf.a 

OBJS		= ${SRCS:.c=.o}

CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}
			
RM			= rm -f

LIB			= ar rc

RAN			= ranlib


${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}
			${RAN} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			
re:			fclean all

.PHONY:		all clean fclean re
