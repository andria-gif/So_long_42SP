# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:06:38 by arosa-di          #+#    #+#              #
#    Updated: 2025/01/28 16:47:06 by arosa-di         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -I $(H_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
RM			=	rm -rf

# path and files
H_SRCS		=	so_long.h
H_DIR		=	include/
HEADER		=	$(addprefix $(H_DIR), $(H_SRCS))

MAPA_SRCS	=	main.c maps_read.c maps_valid.c utils.c
MAPA_DIR	=	src/
OBJ_DIR		=	build/
OBJ_M		=	$(addprefix $(OBJ_DIR), $(MAPA_SRCS:.c=.o))

MAPA		=	$(addprefix $(MAPA_DIR), $(MAPA_SRCS))

LIBFT_DIR	=	library/libft/
LIBFT		=	$(LIBFT_DIR)libft.a

MLX_DIR	=	library/minilibx-linux/
MLX		=	$(MLX_DIR)libmlx.a
MLX_F	=	-L$(MLX_DIR) -lmlx -lX11 -lXext

# Colors
RED  = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

# Rules
$(OBJ_DIR)%.o: $(MAPA_DIR)%.c $(HEADER)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@
			

$(NAME): $(OBJ_M) $(LIBFT) $(MLX)
			$(CC) $(FLAGS) $(OBJ_M) $(LIBFT) $(MLX_F) -o $(NAME)
			@echo -e "$(GREEN)Execution completed: $(NAME) created!$(DEFAULT)"

$(LIBFT):
			@make -C $(LIBFT_DIR)

$(MLX):
			@make -C $(MLX_DIR)

all:		$(NAME)

clean:
			@$(RM) $(OBJ_M)
			@make clean -C $(LIBFT_DIR)
			@make clean -C $(MLX_DIR)
			@echo -e "$(YELLOW)execution completed!$(DEFAULT)"

fclean: clean
			@$(RM) $(NAME)
			@make fclean -C $(LIBFT_DIR)
			@echo -e "$(RED)all execution completed!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re
