/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:47:22 by suhong            #+#    #+#             */
/*   Updated: 2021/05/13 12:08:17 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static int	a_three(t_stack *a, t_stack *b, size_t size)
{
	if (get_stack_size(*a) == 3)
	{
		while (!sort_check(a))
		{
			if (a->tail->content > a->tail->pre->content
				&& a->tail->content > a ->head->content)
				print_order("ra", a, b);
			else if (a->tail->content > a->tail->pre->content)
			{
				if (print_order("sa", a, b) == ERROR)
					return (ERROR);
			}
			else if (a->tail->content > a->head->content)
				print_order("rra", a, b);
			else
				print_order("ra", a, b);
		}
		return (1);
	}
	if (size < 3)
		return (1);
	return (0);
}

static int	below_three(t_stack *a, t_stack *b, size_t size, int flag)
{
	if (flag)
	{
		if (!stack_empty(a) && !stack_one_left(a))
			if (a->tail->content > a->tail->pre->content)
				if (print_order("sa", a, b) == ERROR)
					return (ERROR);
	}
	else
	{
		if (!stack_empty(b) && !stack_one_left(b))
			if (b->tail->content < b->tail->pre->content)
				if (print_order("sb", a, b) == ERROR)
					return (ERROR);
		while (!stack_empty(b) && size--)
			if (print_order("pa", a, b) == ERROR)
				return (ERROR);
	}
	return (1);
}

int	a_2_b(t_stack *a, t_stack *b, size_t size)
{
	t_chunk	chunk;

	init_chunk(&chunk);
	if (a_three(a, b, size))
		return (below_three(a, b, size, 1));
	if (get_pivot(a, &size, &(chunk.pivot_l), &(chunk.pivot_h)) == ERROR)
		return (ERROR);
	while (size)
	{
		if (a->tail->content >= chunk.pivot_h)
			work_log(a, b, "ra", &(chunk.ra_log));
		else
		{
			if (work_log(a, b, "pb", &(chunk.push_log)) == ERROR)
				return (ERROR);
			if (b->tail->content > chunk.pivot_l)
				work_log(a, b, "rb", &(chunk.rb_log));
		}
		size--;
	}
	rotate_stack(a, b, chunk.ra_log, chunk.rb_log);
	return (a_2_b(a, b, chunk.ra_log)
		| b_2_a(a, b, chunk.rb_log)
		| b_2_a(a, b, chunk.push_log - chunk.rb_log));
}

int	b_2_a(t_stack *a, t_stack *b, size_t size)
{
	t_chunk	chunk;

	init_chunk(&chunk);
	if (size < 3)
		return (below_three(a, b, size, 0));
	if (get_pivot(b, &size, &(chunk.pivot_l), &(chunk.pivot_h)) == ERROR)
		return (ERROR);
	while (size)
	{
		if (b->tail->content <= chunk.pivot_l)
			work_log(a, b, "rb", &(chunk.rb_log));
		else
		{
			if (work_log(a, b, "pa", &(chunk.push_log)) == ERROR)
				return (ERROR);
			if (a->tail->content < chunk.pivot_h)
				work_log(a, b, "ra", &(chunk.ra_log));
		}
		size--;
	}
	if (a_2_b(a, b, chunk.push_log - chunk.ra_log) == ERROR)
		return (ERROR);
	rotate_stack(a, b, chunk.ra_log, chunk.rb_log);
	return (a_2_b(a, b, chunk.ra_log) | b_2_a(a, b, chunk.rb_log));
}
