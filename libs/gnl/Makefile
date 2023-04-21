# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:29:25 by zhamdouc          #+#    #+#              #
#    Updated: 2022/11/23 16:17:45 by zakariyaham      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libget_next_line.a

SRC = get_next_line_utils.c \
	get_next_line.c \

OBJ = ${SRC:.c=.o}

COMPIL = gcc -Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJ}
	ar rc ${NAME} $^

%.o : %.c
	${COMPIL} -o $@ -c $<

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re :fclean	all
