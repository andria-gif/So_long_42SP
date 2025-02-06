# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:06:38 by arosa-di          #+#    #+#              #
#    Updated: 2025/02/05 18:09:51 by arosa-di         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -I $(H_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
RM			=	rm -rf

# Path and files
H_DIR		=	include/
HEADER		=	$(H_DIR)so_long.h

MAPA_SRCS	=	main.c maps_read.c maps_valid.c utils_game.c
MAPA_DIR	=	src/
OBJ_DIR		=	build/
OBJ_M		=	$(addprefix $(OBJ_DIR), $(MAPA_SRCS:.c=.o))
MAPA		=	$(addprefix $(MAPA_DIR), $(MAPA_SRCS))

LIBFT_DIR	=	library/libft/
LIBFT		=	$(LIBFT_DIR)libft.a

MLX_DIR		=	library/minilibx-linux/
MLX			=	$(MLX_DIR)libmlx.a
MLX_F		=	-L$(MLX_DIR) -lmlx -lX11 -lXext

# Rules
$(NAME): $(OBJ_M) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJ_M) $(LIBFT) $(MLX_F) -o $(NAME)

$(OBJ_DIR)%.o: $(MAPA_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

all: $(LIBFT) $(MLX) $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re