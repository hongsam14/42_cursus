# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 14:33:39 by suhong            #+#    #+#              #
#    Updated: 2021/09/13 22:02:26 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAG = -Wall -Wextra -Werror

INCLUDE = philosophers.h

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
	$(CC) $(CFLAG) -o $@ -c $< -I $(INCLUDE)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(LIB) -o $@ $^

clean :
	$(RM) -rf $(OBJ)

fclean : clean
	$(RM) -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
