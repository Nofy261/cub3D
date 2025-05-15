# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 08:55:30 by nolecler          #+#    #+#              #
#    Updated: 2025/05/15 12:11:51 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./MLX42/include -g
# MLXFLAGS= MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm


SRC_PARSING = $(addprefix parsing/, parse_args.c parse_file.c)
SRC_UTILS = $(addprefix utils/, utils.c)
SRC = $(addprefix src/, main.c $(SRC_PARSING) $(SRC_UTILS))
GET_NEXT_LINE = $(addprefix ../get_next_line/, get_next_line.c get_next_line_utils.c)#le .h a rajouter
INCLUDES = -Iincludes	

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


#============ Colors ========================#

white='\033[1;37m'
dark_green='\033[0;32m'

#================ UTILS PART ================#

RM = rm -f

#all: mlx_build $(NAME)
all: $(NAME)

#$(NAME) : $(OBJ)
#	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME) 
#	@echo $(dark_green)"Executable is ready"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo $(dark_green)"Executable is ready"

#$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
#	mkdir -p $(dir $@)
#	$(CC) $(CFLAGS) $(MLXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: ../get_next_line/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# mlx_build:
# 	@cd MLX42 && cmake -B build
# 	@cd MLX42 && cmake --build build -j4

clean: 
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re

