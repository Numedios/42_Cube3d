# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:30:07 by zhamdouc          #+#    #+#              #
#    Updated: 2022/10/26 18:41:49 by zhamdouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRC = ft_putnbr_base.c \
	ft_putnbr_printf.c \
	ft_printf.c\
	ft_strlen.c \
	f_pba.c \

OBJ = ${SRC:.c=.o}

CFLAGS = gcc -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
	ar rc ${NAME} $^

%.o : %.c
	${CFLAGS} -o $@ -c $<

clean : 
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all