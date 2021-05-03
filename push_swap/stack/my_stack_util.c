/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:29:09 by suhong            #+#    #+#             */
/*   Updated: 2021/05/02 15:55:50 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/my_stack.h"

int	push(t_stack *stack, int content)
{
	t_deck	*add;

	add = (t_deck *)malloc(sizeof(t_deck));
	if (!add)
		return (ERROR);
	add->content = content;
	add->pre = stack->tail;
	add->next = stack->head;
	if (stack_empty(stack))
		stack->head = add;
	else
	{
		stack->tail->next = add;
		stack->head->pre = add;
	}
	stack->tail = add;
	return (OK);
}

int	pop(t_stack *stack, int *content)
{
	t_deck	*tmp;

	if (stack_empty(stack))
		return (0);
	*content = stack->tail->content;
	if (stack_one_left(stack))
	{
		free(stack->tail);
		stack->tail = 0;
		stack->head = 0;
	}
	else
	{
		tmp = stack->tail->pre;
		tmp->next = stack->tail->next;
		free(stack->tail);
		stack->tail = tmp;
		stack->head->pre = stack->tail;
	}
	return (OK);
}

int	sort_check(t_stack *stack)
{
	t_deck	*p;

	if (stack_empty(stack) || stack_one_left(stack))
		return (OK);
	p = stack->tail;
	while (p != stack->head)
	{
		if (p->content < p->pre->content)
			p = p->pre;
		else
			return (0);
	}
	return (OK);
}

int	rev_sort_check(t_stack *stack)
{
	t_deck	*p;

	if (stack_empty(stack) || stack_one_left(stack))
		return (OK);
	p = stack->tail;
	while (p != stack->head)
	{
		if (p->content > p->pre->content)
			p = p->pre;
		else
			return (0);
	}
	return (OK);
}

int	step_count(int input)
{
	static int	step = 0;

	if (input != 0)
		step += input;
	return (step);
}
