# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 12:34:51 by suhong            #+#    #+#              #
#    Updated: 2021/04/30 13:22:49 by suhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME = checker

P_NAME = push_swap

COMMON_SRC = ./stack/my_stack.c\
	    ./stack/my_stack_util.c\
	    ./stack/a_b_control.c\
	    ./check_arg.c\
		./print_stack.c\
	    
C_SRC = $(COMMON_SRC)\
		./check_input.c\
		./checker.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c

P_SRC = $(COMMON_SRC)\
		./sort.c\
		./push_swap.c

C_OBJS = $(C_SRC:.c=.o)

P_OBJS = $(P_SRC:.c=.o)

CC = gcc

CFLAG = -Wall -Wextra -Werror -O3

LIBFT = libft.a

LIBDIR = ./libft

LFLAG = -L. -lft

all : $(C_NAME) $(P_NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(C_NAME) : $(C_OBJS) $(LIBFT)
	      $(CC) $(LFLAG) $(C_OBJS) -o $@

$(P_NAME) : $(P_OBJS) $(LIBFT)
	      $(CC) $(LFLAG) $(P_OBJS) -o $@

$(LIBFT) :
	make -C $(LIBDIR) all
	cp $(LIBDIR)/$@ ./

clean : clean_ft
	rm -f $(C_OBJS)
	rm -f $(P_OBJS)

fclean : clean
	rm -f $(C_NAME)
	rm -f $(P_NAME)

re : fclean all

clean_ft :
	make -C $(LIBDIR) fclean
	rm -f $(LIBFT)
