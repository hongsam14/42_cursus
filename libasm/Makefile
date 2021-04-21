# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 16:41:29 by suhong            #+#    #+#              #
#    Updated: 2021/04/21 16:49:01 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

NASM = nasm

NFLAGS = -f macho64

SRCS = ft_read.s\
       ft_write.s\
       ft_strcmp.s\
       ft_strcpy.s\
       ft_strdup.s\
       ft_strlen.s

OBJS = $(SRCS:.s=.o)

RM = rm -rf

%.o : %.s Makefile
	$(NASM) $(NFLAGS) -o $@ $<

$(NAME) : $(OBJS)
	ar rcs $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re
