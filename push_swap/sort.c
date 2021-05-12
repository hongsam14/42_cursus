/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:47:22 by suhong            #+#    #+#             */
/*   Updated: 2021/05/12 15:18:40 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include <stdio.h>

int	a_2_b(t_stack *a, t_stack *b, size_t size)
{
	int	pivot_l;
	int	pivot_h;
	size_t	ra_log;
	size_t	pb_log;
	size_t	rb_log;
	size_t	i;

	pivot_l = 0;
	pivot_h = 0;
	ra_log = 0;
	pb_log = 0;
	rb_log = 0;
	i = 0;
	if (size < 3)
	{
		if (!stack_empty(a) && !stack_one_left(a))
			if (a->tail->content > a->tail->pre->content)
				if (print_order("sa", a, b) == ERROR)
					return (ERROR);
		return (1);
	}
	get_pivot(a, &size, &pivot_l, &pivot_h);
	while (size--)
	{
		if (a->tail->content >= pivot_h)
		{
			print_order("ra", a, b);
			ra_log++;
		}
		else
		{
			if (print_order("pb", a, b) == ERROR)
				return (ERROR);
			pb_log++;
			if (b->tail->content >= pivot_l)
			{
				print_order("rb", a, b);
				rb_log++;
			}
		}
	}
	while (i < ra_log && i < rb_log)
	{
		print_order("rrr", a, b);
		i++;
	}
	while (i < ra_log)
	{
		print_order("rra", a, b);
		i++;
	}
	while (i < rb_log)
	{
		print_order("rrb", a, b);
		i++;
	}
	return (a_2_b(a, b, ra_log) | b_2_a(a, b, rb_log) | b_2_a(a, b, pb_log - rb_log));
}

int	b_2_a(t_stack *a, t_stack *b, size_t size)
{
	int	pivot_l;
	int	pivot_h;
	size_t	rb_log;
	size_t	pa_log;
	size_t	ra_log;
	size_t	i;

	pivot_l = 0;
	pivot_h = 0;
	rb_log = 0;
	pa_log = 0;
	ra_log = 0;
	i = 0;
	if (size < 3)
	{
		while (!stack_empty(b) && size--)
		{
			if (!stack_one_left(b))
				if (b->tail->content < b->tail->pre->content)
					if (print_order("sb", a, b) == ERROR)
						return (ERROR);
			if (print_order("pa", a, b) == ERROR)
				return (ERROR);
		}
		return (1);
	}
	get_pivot(b, &size, &pivot_l, &pivot_h);
	while (size--)
	{
		if (b->tail->content < pivot_l)
		{
			print_order("rb", a, b);
			rb_log++;
		}
		else
		{
			if (print_order("pa", a, b) == ERROR)
				return (ERROR);
			pa_log++;
			if (a->tail->content < pivot_h)
			{
				print_order("ra", a, b);
				ra_log++;
			}
		}
	}
	if (a_2_b(a, b, pa_log - ra_log) == ERROR)
		return (ERROR);
	while (i < ra_log && i < rb_log)
	{
		print_order("rrr", a, b);
		i++;
	}
	while (i < rb_log)
	{
		print_order("rrb", a, b);
		i++;
	}
	while (i < ra_log)
	{
		print_order("rra", a, b);
		i++;
	}
	return (a_2_b(a, b, ra_log) | b_2_a(a, b, rb_log));
}
