# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:35:46 by kvebers           #+#    #+#              #
#    Updated: 2023/01/02 18:32:51 by kvebers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
NAME_BONUS = so_long_bonus
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
FILES	= src/start.c src/utils.c src/textures.c src/free.c src/init.c \
		  src/hooks.c src/key.c src/init_gates.c src/protection.c \
		  src/protection2.c
B_FILES = src_b/start.c src_b/utils.c src_b/textures.c src_b/free.c \
		src_b/init.c src_b/hooks.c src_b/key.c src_b/init_gates.c \
		src_b/protection.c src_b/protection2.c src_b/stats.c \
		src_b/stats_algo.c src_b/ani_algo.c
LFLAGS	=	-L ./mlx -lmlx
RM = 		rm -f
OBJ	= $(FILES:%.c=%.o)
B_OBJ	= $(B_FILES:%.c=%.o)


all:  $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./MLX42
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a MLX42/libmlx42.a -lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib -o $(NAME)

bonus: $(B_OBJ)
	make -C ./libft
	make -C ./MLX42
	$(CC) $(CFLAGS) $(B_OBJ) libft/libft.a MLX42/libmlx42.a -lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib -o $(NAME_BONUS)

fcleanb:
	@$(RM) $(B_OBJ) ${NAME_BONUS}
	
reb: fcleanb bonus 

clean:
	@make clean -C libft/
	@make clean -C MLX42/
	- @$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	@make fclean -C libft/
	@make fclean -C MLX42/
	- @$(RM) ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: clean fclean all re bonus fcleanb reb