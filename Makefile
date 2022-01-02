# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 11:12:05 by mmoumni           #+#    #+#              #
#    Updated: 2022/01/02 19:29:25 by mmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRC_DIR = src
# OBJ_DIR = obj
# BIN_DIR = .

# SRC = $(wildcard $(SRC_DIR)/*.c)
# SRC_BONUS = $(wildcard $(SRC_DIR)/*_bonus.c)
# OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR)/%_bonus.c=$(OBJ_DIR)/%_bonus.o)

SRC = bresnham.c get_next_line_utils.c setting.c create_matrix.c ft_atoi.c isometric.c stack.c \
	data_init.c ft_atoi_hex.c draw_map.c ft_split.c key_handle.c fdf.c get_next_line.c read_map.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = bresnham.c fdf_bonus.c get_next_line_utils.c setting.c create_matrix.c ft_atoi.c isometric.c stack.c \
	data_init.c ft_atoi_hex.c key_handel_bonus.c draw_map.c ft_split.c get_next_line.c read_map.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)


CC_FLAGS = -Wall -Wextra -Werror
CC = cc

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MATH_FLAGS = -lm

NAME = fdf
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@
	
%.o: %.c 
	$(CC) $(CC_FLAGS) -c $<

bonus: $(OBJ_BONUS)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME)
	
clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all
