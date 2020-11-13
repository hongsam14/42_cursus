# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 17:46:48 by suhong            #+#    #+#              #
#    Updated: 2020/11/13 12:21:30 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

LIBDIR = ./libft

SRCS = ft_print_format.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_read_format.c \
		ft_print_format.c \
		read_s_type.c \
		read_p_type.c \
		read_c_type.c \
		read_percent_type.c \
		read_di_type.c \
		read_ux_type.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT) :
	cd $(LIBDIR); $(MAKE) all

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBDIR)/$(LIBFT) ./$(NAME)
	ar rcs $(NAME) $(OBJS)

clean :
	cd $(LIBDIR); $(MAKE) clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(LIBDIR)/$(LIBFT)
	rm -f $(NAME)

.PHONY : re fclean clean all
