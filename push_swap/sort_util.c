/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:31:20 by suhong            #+#    #+#             */
/*   Updated: 2021/05/13 12:06:34 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	init_chunk(t_chunk *chunk)
{
	chunk->push_log = 0;
	chunk->ra_log = 0;
	chunk->rb_log = 0;
	chunk->pivot_l = 0;
	chunk->pivot_h = 0;
}

int	chunk_sort_check(t_stack *stack, size_t size, int flag)
{
	t_deck	*p;

	if (stack_empty(stack) || stack_one_left(stack))
		return (OK);
	p = stack->tail;
	while (size-- && p != stack->head)
	{
		if (flag)
		{
			if (p->content < p->pre->content)
				p = p->pre;
			else
				return (0);
		}
		else
		{
			if (p->content > p->pre->content)
				p = p->pre;
			else
				return (0);
		}
	}
	return (1);
}

int	work_log(t_stack *a, t_stack *b, char *str, size_t *log)
{
	if (print_order(str, a, b) == ERROR)
		return (ERROR);
	*log = *log + 1;
	return (1);
}

void	rotate_stack(t_stack *a, t_stack *b, size_t ra, size_t rb)
{
	size_t	i;

	i = 0;
	if (!(ra == 2 && get_stack_size(*a) == 2))
	{
		while (i < ra && i < rb)
			work_log(a, b, "rrr", &i);
		while (i < ra)
			work_log(a, b, "rra", &i);
	}
	while (i < rb)
		work_log(a, b, "rrb", &i);
}
