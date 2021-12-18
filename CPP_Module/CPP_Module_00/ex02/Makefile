# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 02:51:37 by suhong            #+#    #+#              #
#    Updated: 2021/12/18 13:37:34 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp \
       tests.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = Account.hpp

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME) : $(OBJS)
	    $(CC) $(CFLAGS) -o $@ $^ -I $(INCS)

re : fclean all

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

.PHONY : all re clean fclean
