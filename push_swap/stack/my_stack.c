/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:04:08 by suhong            #+#    #+#             */
/*   Updated: 2021/04/27 16:19:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/my_stack.h"

int	stack_init(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (ERROR);
	(*stack)->head = 0;
	(*stack)->tail = 0;
	return (OK);
}

int	stack_empty(t_stack *stack)
{
	if (!stack->head && !stack->tail)
		return (1);
	return (0);
}

int	stack_one_left(t_stack *stack)
{
	if (stack->head == stack->tail)
		return (1);
	return (0);
}

void	stack_destroy(t_stack *stack)
{
	int	content;

	while (pop(stack, &content))
	{
	}
	free(stack);
}

size_t	get_stack_size(t_stack stack)
{
	size_t	i;
	t_deck	*p;

	i = 0;
	p = stack.head;
	if (!p)
		return (i);
	i++;
	while (p != stack.tail)
	{
		i++;
		p = p->next;
	}
	return (i);
}
