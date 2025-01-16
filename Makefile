# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:06:38 by arosa-di          #+#    #+#              #
#    Updated: 2025/01/16 17:30:42 by arosa-di         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Wall -Werror -Wextra
CC = cc 
MLX = libft/MLX42/build/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm -lXext

NAME = so_long

LIBFT = libft/lib/libft.a

SRCS = src/main.c\
	
OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

./$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	make -C libft/lib

$(MLX):
	cmake  -S libft/MLX42 -B libft/MLX42/build
	cmake  -S libft/MLX42 --build libft/MLX42/build 
	make -C libft/MLX42/build
	
%.o: %.c
	$(CC) $(CFLAGS) -I include -I libft/lib -I libft/MLX42  -I src/get_next_line -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft/lib clean
	make -C libft/MLX42/build clean

fclean: clean
	rm -f $(NAME)
	make -C libft/lib fclean
	rm -rf libft/MLX42/build

valgrind: $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)
	
re: fclean all

.PHONY: all clean fclean re