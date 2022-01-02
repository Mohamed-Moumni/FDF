# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 11:12:05 by mmoumni           #+#    #+#              #
#    Updated: 2022/01/02 12:17:12 by mmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = .

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC_FLAGS = -Wall -Wextra -Werror
CC = cc

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MATH_FLAGS = -lm

NAME = fdf
all: $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@
	
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all
