/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:42:31 by suhong            #+#    #+#             */
/*   Updated: 2021/04/23 20:42:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STACK_H
# define MY_STACK_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ERROR	0

typedef struct	s_deck
{
	int	content;
	struct s_deck	*next;
	struct s_deck	*pre;
}	t_deck;

typedef struct	s_stack
{
	t_deck	*deck;
	t_deck	*head;
	t_deck	*tail;
}	t_stack

int	stack_init(t_stack *stack);
int	stack_destroy(t_stack *stack);

int	push(t_stack *stack, int add);
int	pop(t_stack *stack);
int	shift_up(t_stack *stack);
int	shift_down(t_stack *stack);

#endif
