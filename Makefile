# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 08:55:30 by nolecler          #+#    #+#              #
#    Updated: 2025/06/13 11:16:27 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes -Iget_next_line -I$(MLXDIR) -Ilibft
MLXDIR  = mlx
MLX_LIB = -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz
LIBFTDIR = libft
LIBFT_LIB = -L$(LIBFTDIR) -lft

SRC_INIT = $(addprefix init/, init.c)
SRC_PARSING = $(addprefix parsing/, parse_args.c get_file.c parse_file.c parse_colors.c parse_map.c map.c)
SRC_UTILS = $(addprefix utils/, exit.c free.c string.c)
SRC_RAYCASTING = $(addprefix raycasting/, raystart.c collision.c input.c raycast.c render.c utils.c)
GET_NEXT_LINE = $(addprefix get_next_line/, get_next_line.c)
SRC = $(addprefix src/, main.c $(SRC_PARSING) $(SRC_UTILS) $(SRC_INIT) $(SRC_RAYCASTING)) $(GET_NEXT_LINE)

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

violet='\033[1;35m'

all: libft_build mlx_build $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)
	@echo $(violet)"Executable is ready"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft_build:
	@$(MAKE) -C $(LIBFTDIR)

mlx_build:
	@$(MAKE) -C $(MLXDIR)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean
	@$(MAKE) -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re libft_build mlx_build