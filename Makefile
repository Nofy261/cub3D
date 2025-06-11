# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 08:55:30 by nolecler          #+#    #+#              #
#    Updated: 2025/06/11 18:58:15 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes -Iget_next_line -I$(MLXDIR)
MLXDIR  = mlx
MLX_LIB = -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz

SRC_INIT = $(addprefix init/, init.c)
SRC_PARSING = $(addprefix parsing/, parse_args.c get_file.c parse_file.c parse_colors.c parse_map.c map.c)
SRC_UTILS = $(addprefix utils/, utils_0.c utils_1.c utils_2.c free.c string.c)
SRC_RAYCASTING = $(addprefix raycasting/, raystart.c raycast.c utils.c)
GET_NEXT_LINE = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)#le .h a rajouter
SRC = $(addprefix src/, main.c $(SRC_PARSING) $(SRC_UTILS) $(SRC_INIT) $(SRC_RAYCASTING)) $(GET_NEXT_LINE)

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

violet='\033[1;35m'

all: mlx_build $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME) 
	@echo $(violet)"Executable is ready"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

mlx_build:
	@$(MAKE) -C $(MLXDIR)

clean: 
	rm -f $(OBJ)
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re