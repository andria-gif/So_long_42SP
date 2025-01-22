# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:06:38 by arosa-di          #+#    #+#              #
#    Updated: 2025/01/21 17:12:53 by arosa-di         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
INC_DIR = include

# Lista de arquivos fonte
SRC = $(SRC_DIR)/maps_read.c \
      $(SRC_DIR)/main.c

# Lista de objetos a serem gerados
OBJS = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

# Compilador e flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_DIR = library/minilibx-linux

# Diretórios da libft
LIBFT_DIR = library/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Flags de link
LDFLAGS = -L $(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Regra principal
all: $(NAME)

# Compilar o jogo
$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR)  # Garantir que a libft seja compilada
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

# Limpeza
clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilar tudo
re: fclean all

.PHONY: all clean fclean re
