# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 17:25:55 by suhong            #+#    #+#              #
#    Updated: 2022/01/04 17:37:59 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myKaren

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Karen.cpp\
       main.cpp\

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
