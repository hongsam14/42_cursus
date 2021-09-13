# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 14:33:39 by suhong            #+#    #+#              #
#    Updated: 2021/09/13 14:45:54 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = gcc

CFLAG = -Wall -Wextra -Werror

LIB = -lpthread

RM = rm

SRC = fork.c\
	ft_util.c\
	ft_util2.c\
	philosopher.c\
	table.c\
	main.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(LIB) -o $@ $^

clean :
	$(RM) -rf $(OBJ)

fclean : clean
	$(RM) -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
