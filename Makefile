# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 12:43:00 by jchamorr          #+#    #+#              #
#    Updated: 2022/06/17 22:54:20 by jchamorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/so_long.c\
		src/utils.c\
		src/map_error.c\
		src/mlx_things.c\
		src/movements.c\

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc -fsanitize=address -g3
FLAGS = -Wall -Wextra -Werror

RM = rm -rf
MLX = -L mlx -lmlx -framework OpenGL -framework Appkit
SAN = -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@ -Imlx

$(NAME): $(OBJS) $(LIBFT)
	@make -C mlx/
	@make -C libft/
	@$(CC) $(FLAGS) $(LIBFT) $^ -o  $@ $(MLX)

clean:
	$(RM) $(OBJS)
	@make clean -C mlx/
	@make clean -C libft/

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re