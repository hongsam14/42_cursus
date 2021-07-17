# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 15:42:00 by suhong            #+#    #+#              #
#    Updated: 2021/07/17 10:43:11 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

LIBFT = libft.a
FTLIB = -L. -lft

#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
# CFLAGS = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
RM = rm

SRC_DIR = src
INC_DIR = include
GNL_DIR = get_next_line

INCLUDE = $(addprefix $(INC_DIR)/, \
	pipex.h \
	libft.h \
	get_next_line.h \
)

GNL = $(addprefix $(GNL_DIR)/, \
	get_next_line.c \
	get_next_line_utils.c \
)

SRC = $(addprefix $(SRC_DIR)/, \
	main.c \
	ft_error.c \
	ft_exec.c \
	ft_pipe.c \
	ft_util.c \
	ft_parse.c \
	ft_split_token.c \
	ft_pipex.c \
)

SRC_BONUS = $(addprefix $(SRC_DIR)/, \
	main_bonus.c \
	ft_error.c \
	ft_exec.c \
	ft_pipe.c \
	ft_util.c \
	ft_parse.c \
	ft_split_token.c \
	ft_pipex.c \
)

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
GNL_OBJ = $(GNL:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT) :
	make -C ./libft
	cp ./libft/$(LIBFT) .

fclean_libft :
	make -C ./libft fclean
	$(RM) -rf $(LIBFT)

$(NAME) : $(LIBFT) $(OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(FTLIB) $(OBJ) $(GNL_OBJ) -o $(NAME) -I $(INC_DIR)

bonus : $(LIBFT) $(OBJ_BONUS) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(FTLIB) $(OBJ_BONUS) $(GNL_OBJ) -o $(NAME_BONUS) -I $(INC_DIR)

clean : fclean_libft
	$(RM) -rf $(OBJ)
	$(RM) -rf $(OBJ_BONUS)
	$(RM) -rf $(GNL_OBJ)

fclean : clean
	$(RM) -rf $(NAME)
	$(RM) -rf $(NAME_BONUS)

re : fclean all

.PHONY: all make_libft fclean_libft clean fclean re bonus
