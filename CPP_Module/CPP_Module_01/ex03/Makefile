# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 00:21:43 by suhong            #+#    #+#              #
#    Updated: 2021/12/31 02:19:15 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = HumanA.cpp\
       HumanB.cpp\
       Weapon.cpp\
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

re : fclean all

.PHONY : all clean fclean re
