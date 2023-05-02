# Compilation flags
ifeq ($(DMEM),1)
MEM 		= -fsanitize=address
endif

ifeq ($(DTHREAD),1)
MEM 		= -fsanitize=thread
endif

#==============================================================================#
#                                   TARGETS                                    #
#==============================================================================#

NAME = minishell

#==============================================================================#
#                                   COMMANDS                                   #
#==============================================================================#

CC = cc
CFLAGS = -g 
MLXFLAGS := -L mlx_linux -lmlx -lXext -lX11 -lz -lm
DFLAGS = -MMD
MKDIR = mkdir -p
RM = rm -f
MAKE_SILENT = make --no-print-directory

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

PURPLE = \033[35m
GREEN = \033[32m
YELLOW = \033[33m
END = \033[0m

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_DIR = src/
HEADER_DIR = include/
OBJ_DIR = obj/

#==============================================================================#
#                                   SOURCES                                    #
#==============================================================================#

SRC = main.c \
		get_next_line.c \
		get_next_line_utils.c \
		parsing_arg.c \
		supp.c \
		free.c \
		create_tab.c \
		set_struct.c \
		create_sprites_utils.c \
		create_sprites.c \
		create_map.c \
		create_map_utils.c \
		parsing_map_utils.c \
		create_player.c \
		libft.c \
		2d.c \


#==============================================================================#
#                                   HEADERS                                    #
#==============================================================================#

HEAD_NAME = $(HEADER_DIR)/minishell.h
INC = -I./$(HEADER_DIR)

#==============================================================================#
#                                   OBJECTS                                    #
#==============================================================================#

OBJ = $(addprefix ${OBJ_DIR}, ${SRC:.c=.o})

#==============================================================================#
#                                   LIBS                                       #
#==============================================================================#

MLX := mlx_linux/libmlx_Linux.a


#==============================================================================#
#                                   MAKEFILE                                   #
#==============================================================================#

all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEAD_NAME)
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(DFLAGS) ${MLX} $(MEM) $(INC) -c $< -o $@

$(NAME) : $(OBJ)
	echo "$(YELLOW)Making cube3d$(END)"
	$(CC) $(CFLAGS) $(OBJ) ${MLXFLAGS} -o $(NAME) -lreadline
	echo "$(GREEN)Done$(END)"

bonus : all

clean :
	echo "$(PURPLE)Cleaning cube3d objects...$(END)"
	$(RM)r $(OBJ_DIR)
	echo "$(GREEN)Done$(END)"

fclean : clean
	echo "$(PURPLE)Cleaning cube3d...$(END)"
	$(RM) $(NAME)
	echo "$(GREEN)Done$(END)"

re : fclean
	$(MAKE_SILENT) all

.PHONY : all clean fclean re bonus
.SILENT :
