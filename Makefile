# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:06:38 by arosa-di          #+#    #+#              #
#    Updated: 2025/01/20 18:56:20 by arosa-di         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = ./src
INC_DIR = ./inclunde

# List of files
SRC = src/maps_read.c \
      src/main.c \

# Compilers and flags
CC = cc
CFLAGS = -I$(INC_DIR) -Ilibft
MLX_DIR = ./library/minilibx-linux
CFLAGS = -I./inclunde -I./library/minilibx-linux -I./library/libft

# Libft directories
LIBFT_DIR = ./library/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Link flags
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext

# Main rule
all: $(LIBFT) $(NAME)

# Compile the game
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compile Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Cleaning
clean:
	rm -rf $(NAME)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

valgrind: $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
