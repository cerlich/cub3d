# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 22:29:24 by cerlich           #+#    #+#              #
#    Updated: 2021/03/12 15:20:32 by cerlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

HEAD = cub3d.h

SRCS =  save.c \
		draw_sprites.c \
		get_img.c \
		main.c \
		parse_sprites.c \
		sprites.c \
		check_empty_space.c \
		draw_walls.c \
		get_next_line.c \
		parse_map.c \
		check_map.c \
		parser.c \
		color.c \
		free.c \
		list.c \
		move.c \
		render.c \
		parse_config.c \
		error.c
		
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

OBJS =$(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx/libmlx.a

all: $(LIBFT) $(MLX) $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(MLX_FLAGS) $(SRCS) -o $(NAME) 
	
$(OBJS) : %.o : %.c $(HEAD)

$(LIBFT):
	(cd libft; make all)

$(MLX):
	(cd minilibx; make all)

bonus :
	make all

norm :
	@norminette *.c *.h libft/*.c libft/*.h

clean :
	(cd libft; make clean)
	rm -f $(OBJS)

fclean : clean
	(cd libft; make fclean)
	(cd minilibx; make clean)
	rm -f $(NAME)
re : fclean all
