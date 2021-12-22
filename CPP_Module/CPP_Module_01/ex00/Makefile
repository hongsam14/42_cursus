# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 15:51:14 by suhong            #+#    #+#              #
#    Updated: 2021/12/23 01:19:19 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp\
       Zombie.cpp\
       newZombie.cpp\
       randomChump.cpp\

OBJS = $(SRCS:.cpp=.o)

INCS = Zombie.hpp

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
