# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 03:51:15 by suhong            #+#    #+#              #
#    Updated: 2021/12/31 02:19:51 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieHorde

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp\
       ZombieHorde.cpp\
       main.cpp\

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -I.

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : clean all

.PHONY : all clean fclean re
