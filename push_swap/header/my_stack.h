/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:42:31 by suhong            #+#    #+#             */
/*   Updated: 2021/04/29 13:56:57 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STACK_H
# define MY_STACK_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR	-1
# define OK		1

typedef struct		s_deck
{
	int				content;
	struct s_deck	*pre;
	struct s_deck	*next;
}					t_deck;

typedef struct		s_stack
{
	t_deck			*head;
	t_deck			*tail;
}					t_stack;

int					stack_init(t_stack **stack);
int					stack_empty(t_stack *stack);
int					stack_one_left(t_stack *stack);
void				stack_destroy(t_stack *stack);
size_t				get_stack_size(t_stack stack);

int					push(t_stack *stack, int add);
int					pop(t_stack *stack, int *content);
int					sort_check(t_stack *stack);

int					swap_order(t_stack *stack);
int					push_order(t_stack *from, t_stack *to);
int					rotate_order(t_stack *stack);
int					rev_rotate_order(t_stack *stack);
int					dble_order(t_stack *a, t_stack *b, int (*func)(t_stack *));

#endif
