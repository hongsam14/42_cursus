/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:45:51 by suhong            #+#    #+#             */
/*   Updated: 2021/04/29 13:57:14 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/my_stack.h"

int	swap_order(t_stack *stack)
{
	int	tmp1;
	int	tmp2;

	if (stack_empty(stack) || stack_one_left(stack))
		return (0);
	pop(stack, &tmp1);
	pop(stack, &tmp2);
	push(stack, tmp1);
	push(stack, tmp2);
	return (OK);
}

int	push_order(t_stack *from, t_stack *to)
{
	int	tmp;

	if (!pop(from, &tmp))
		return (0);
	return (push(to, tmp));
}

int	rotate_order(t_stack *stack)
{
	if (stack_empty(stack) || stack_one_left(stack))
		return (0);
	stack->head = stack->head->pre;
	stack->tail = stack->tail->pre;
	return (OK);
}

int	rev_rotate_order(t_stack *stack)
{
	if (stack_empty(stack) || stack_one_left(stack))
		return (0);
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	return (OK);
}

int	dble_order(t_stack *a, t_stack *b, int (*func)(t_stack *))
{
	if (func(a) == ERROR)
		return (ERROR);
	if (func(b) == ERROR)
		return (ERROR);
	return (OK);
}
