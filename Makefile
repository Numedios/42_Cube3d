# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:57:01 by zakariyaham       #+#    #+#              #
#    Updated: 2022/11/30 17:40:39 by zhamdouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_PATH = ./srcs/
SRC = ft_main.c \
	ft_path.c ft_check.c ft_free.c ft_child.c
SRCS = $(addprefix ${SRC_PATH}, ${SRC})

OBJ_PATH	= obj/
OBJ = ${SRC:.c=.o}
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

DEPS = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

INC = -I./includes/

LIBS = -L./libs/libft -lft -L./libs/printf -lprintf -L./libs/gnl -lget_next_line # -L./libs/minilibx-linux -lmlx -lXext -lX11 -lm -lz

FLAGS = -Wall -Wextra -Werror -MMD -MP -g

${NAME} : ${OBJS}
	make -C ./libs/libft/
	make -C ./libs/printf/
	make -C ./libs/gnl/
#	make -C ./libs/minilibx-linux/
	clang ${FLAGS} $(OBJS) $(LIBS) -o ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	clang ${FLAGS} ${INC} -o $@ -c $<

all : ${NAME}

clean :
	make clean -C ./libs/libft/
	make clean -C ./libs/printf/
	make clean -C ./libs/gnl/
#	make clean -C ./libs/minilibx-linux/
	rm -rf ${OBJ_PATH}

fclean : clean
	make fclean -C ./libs/libft/
	make fclean -C ./libs/printf/
	make clean -C ./libs/gnl/
	rm -rf ${NAME}

re : fclean all

-include ${DEPS}

.SECONDARY : $(OBJS)

.PHONY: all clean fclean re
