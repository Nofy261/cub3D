# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 08:55:30 by nolecler          #+#    #+#              #
#    Updated: 2025/06/02 11:18:17 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./MLX42/include -g
MLXFLAGS= MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm


SRC_INIT = $(addprefix init/, init.c)
SRC_PARSING = $(addprefix parsing/, parse_args.c get_file.c parse_file.c parse_colors.c parse_map.c)
SRC_UTILS = $(addprefix utils/, utils_0.c utils_1.c utils_2.c free.c)
GET_NEXT_LINE = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)#le .h a rajouter
INCLUDES = -Iincludes -Iget_next_line
SRC = $(addprefix src/, main.c $(SRC_PARSING) $(SRC_UTILS) $(SRC_INIT)) $(GET_NEXT_LINE)

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))



violet='\033[1;35m'

RM = rm -f

all: mlx_build $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME) 
	@echo $(violet)"Executable is ready"


$(OBJ_DIR)/%.o: get_next_line%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#mlx_build:
#	@cd MLX42 && cmake -B build
#	@cd MLX42 && cmake --build build -j4

mlx_build:
	@cd MLX42 && cmake -B build > /dev/null 2>&1
	@cd MLX42 && cmake --build build -j4


clean: 
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re

