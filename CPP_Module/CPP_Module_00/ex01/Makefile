# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 16:35:17 by suhong            #+#    #+#              #
#    Updated: 2021/12/13 18:18:53 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = contact.cpp \
       phonebook.cpp \
       prompt.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = phonebook.hpp

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
