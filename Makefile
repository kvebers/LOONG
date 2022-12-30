# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:35:46 by kvebers           #+#    #+#              #
#    Updated: 2022/12/30 11:58:37 by kvebers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
FILES	= src/start.c src/utils.c src/textures.c src/free.c src/init.c \
		  src/hooks.c src/key.c src/init_gates.c src/protection.c
LFLAGS	=	-L ./mlx -lmlx
RM = 		rm -f
OBJ	= $(FILES:%.c=%.o)

all:  $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./MLX42
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a MLX42/libmlx42.a -lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib -o $(NAME)

clean:
	@make clean -C libft/
	- @$(RM) $(OBJ)

fclean: clean
	@make fclean -C libft/
	- @$(RM) ${NAME}

re: fclean all

.PHONY: clean fclean all re