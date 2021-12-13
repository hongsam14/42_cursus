# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 11:33:05 by suhong            #+#    #+#              #
#    Updated: 2021/12/13 21:55:49 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = megaphone

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $<

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : re clean fclean all
