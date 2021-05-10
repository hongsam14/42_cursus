/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:47:22 by suhong            #+#    #+#             */
/*   Updated: 2021/05/10 12:36:14 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include <stdio.h>

int	quick_a_2_b(t_stack *a, t_stack *b, size_t size)
{
	int	pivot;
	size_t	ra_log;
	size_t	pb_log;
	size_t	i;

	pivot = 0;
	ra_log = 0;
	pb_log = 0;
	i = 0;
#if 0
	if (size < 2)
		return (1);
#else
	if (size < 3)
	{
		if (a->tail->content > a->tail->pre->content)
			if (print_order("sa", a, b) == ERROR)
				return (ERROR);
		return (1);
	}
#endif
	printf("a_stack size:%zu, size:%zu\n", get_stack_size(*a), size);
	if (!get_pivot(a->tail, size, &pivot))
		return (ERROR);
	while (size--)
	{
		if (a->tail->content > pivot)
		{
			print_order("ra", a, b);
			ra_log++;
		}
		else
		{
			if (print_order("pb", a, b) == ERROR)
				return (ERROR);
			pb_log++;
		}
	}
	while (i++ < ra_log)
		print_order("rra", a, b);
	quick_a_2_b(a, b, ra_log);
	quick_b_2_a(a, b, pb_log);
	return (1);
}

int	quick_b_2_a(t_stack *a, t_stack *b, size_t size)
{
	int	pivot;
	size_t	rb_log;
	size_t	pa_log;
	size_t	i;

	pivot = 0;
	rb_log = 0;
	pa_log = 0;
	i = 0;
	if (size < 3)
	{
		if (!stack_empty(b) || !stack_one_left(b))
			if (b->tail->content < b->tail->pre->content)
				if (print_order("sb", a, b) == ERROR)
					return (ERROR);
		while (!stack_empty(b))
			if (print_order("pa", a, b) == ERROR)
				return (ERROR);
		return (1);
	}
	printf("b_stack size:%zu, size:%zu\n", get_stack_size(*b), size);
	if (!get_pivot(b->tail, size, &pivot))
		return (ERROR);
	while (size--)
	{
		if (b->tail->content > pivot)
		{
			print_order("rb", a, b);
			rb_log++;
		}
		else
		{
			if (print_order("pa", a, b) == ERROR)
				return (ERROR);
			pa_log++;
		}
	}
	while (i++ < rb_log)
		print_order("rrb", a, b);
	quick_a_2_b(a, b, pa_log);
	quick_b_2_a(a, b, rb_log);
	return (1);
}
