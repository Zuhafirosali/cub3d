# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 15:37:39 by faal-zub          #+#    #+#              #
#    Updated: 2024/06/21 16:19:09 by faal-zub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT = libft/libft.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = main.c utils.c key_press.c loop_assign.c \
		map_validity_check.c parsing.c verline.c action.c free.c move_player.c \
		help_analys.c set_player.c analys_map.c element_analys.c \
		malloc_map.c set_map.c start_map.c
OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C mlx
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
