# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 14:18:18 by suhong            #+#    #+#              #
#    Updated: 2021/03/23 18:49:50 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = libft.a

LIBMLX = libmlx.a

LIBMLXBETA = libmlx_beta.dylib

CC = gcc

CFLAG = -Wall -Wextra -Werror

MFLAG = -fsanitize=address -O1

LFLAG = -L. -lft -lmlx -lmlx_beta

MLXFLAG = -framework OpenGl -framework AppKit

SRCS = ./base/debug.c \
	   ./base/get_vector.c \
	   ./base/vector.c \
	   ./base/window.c \
	   ./base/texture.c \
	   ./base/color.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_line_utils.c \
	   ./controler/controler.c \
	   ./engine/check_pool.c \
	   ./engine/collider.c \
	   ./engine/dda_util.c \
	   ./engine/draw_sprite.c \
	   ./engine/draw_wall.c \
	   ./engine/gradient.c \
	   ./engine/player.c \
	   ./engine/screen.c \
	   ./engine/sprite_collision.c \
	   ./engine/collision.c \
	   ./parse/read_world.c \
	   ./parse/read_map.c \
	   ./parse/parse_util.c \
	   ./parse/search_map.c \
	   ./parse/search_util.c \
	   ./engine.c \
	   ./parse.c \
	   ./load.c \
	   ./cub3d.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(LIBMLX) $(LIBMLXBETA)
	${CC} ${MLXFLAG} ${LFLAG} ${OBJS} $(MFLAG) -o $@

%.o : %.c
	$(CC) -c $< -o $@

fclean : clean
	rm -f $(NAME)

clean : clean_ft clean_mlx clean_mlx_beta
	rm -f $(OBJS)

re : fclean all

$(LIBFT) :
	make -C ./libft all
	cp ./libft/$@ ./

$(LIBMLX) :
	make -C ./mlx all
	cp ./mlx/$@ ./

$(LIBMLXBETA) :
	make -C ./mlx_beta all
	cp ./mlx_beta/$@ ./

clean_ft :
	make -C ./libft fclean
	rm -f $(LIBFT)

clean_mlx :
	make -C ./mlx clean
	rm -f $(LIBMLX)

clean_mlx_beta :
	make -C ./mlx_beta clean
	rm -f $(LIBMLXBETA)

.PHONY : all, fclean, clean, re
